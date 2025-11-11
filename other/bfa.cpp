#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

void bellmanFord(int V, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V-1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v])
                dist[e.v] = dist[e.u] + e.wt;
        }
    }

    // Check for negative weight cycles
    for (auto &e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    cout << "Vertex distances from source:\n";
    for (int i = 0; i < V; i++) cout << i << " -> " << dist[i] << endl;
}

int main() {
    int V = 5;
    vector<Edge> edges = {{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}};
    bellmanFord(V, edges, 0);
    return 0;
}

// TC = O(v*e)
// SC = O(v*e)