#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dist;

int tsp(int curr, vector<bool> &visited) {
    // check if all cities visited
    bool allVisited = true;
    for (bool v : visited) {
        if (!v) {
            allVisited = false;
            break;
        }
    }
    if (allVisited) return dist[curr][0]; // return to start

    int ans = INT_MAX;
    for (int next = 0; next < n; next++) {
        if (!visited[next]) {
            visited[next] = true;
            ans = min(ans, dist[curr][next] + tsp(next, visited));
            visited[next] = false; // backtrack
        }
    }
    return ans;
}

int main() {
    cin >> n;
    dist.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    vector<bool> visited(n, false);
    visited[0] = true; // start at city 0
    int minCost = tsp(0, visited);

    cout << "Minimum TSP cost: " << minCost << endl;
    return 0;
}


// Time Complexity	O(n!)
// Space Complexity	O(n²) (due to distance matrix)