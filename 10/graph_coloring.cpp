#include <iostream>
#include <vector>
using namespace std;

// Check if it is safe to color vertex v with color c
bool isSafe(const vector<vector<int>>& graph, vector<int>& color, int v, int c) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c)
            return false; // adjacent vertex has same color
    }
    return true;
}

// Recursive backtracking to color the graph
bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    int n = graph.size();
    if (v == n) // all vertices are colored
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(graph, color, v, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; // backtrack
        }
    }
    return false; // no color can be assigned
}

// Try coloring with 1..n colors to find minimum
int minGraphColoring(const vector<vector<int>>& graph, vector<int>& finalColoring) {
    int n = graph.size();
    for (int m = 1; m <= n; m++) {
        vector<int> color(n, 0);
        if (graphColoringUtil(graph, m, color, 0)) {
            finalColoring = color;
            return m;
        }
    }
    return n; // fallback, should not happen
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 or 1):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    vector<int> coloring;
    int minColors = minGraphColoring(graph, coloring);

    cout << "Minimum number of colors required: " << minColors << endl;
    cout << "Coloring assignment (vertex: color):\n";
    for (int i = 0; i < n; i++)
        cout << "Vertex " << i << ": " << coloring[i] << endl;

    return 0;
}

// TC = O(m*v)
// SC = O(v)