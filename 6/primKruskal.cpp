#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool custom_comparator(Edge a, Edge b) {
    return a.weight < b.weight;
}

bool hasCycle(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u, adj, visited)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

void kruskal_algo(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), custom_comparator);

    vector<vector<int>> adj(n);
    vector<pair<int,int>> mst_edges;
    int mst_weight = 0;

    for (auto e : edges) {
        // Add edge temporarily
        adj[e.u].push_back(e.v);
        adj[e.v].push_back(e.u);

        // Check for cycle
        vector<bool> visited(n, false);
        if (hasCycle(0, -1, adj, visited)) {
            // Cycle detected, remove edge
            adj[e.u].pop_back();
            adj[e.v].pop_back();
        } else {
            // No cycle, include edge in MST
            mst_edges.push_back({e.u, e.v});
            mst_weight += e.weight;
        }
    }

    cout << "Kruskal MST weight: " << mst_weight << endl;
    cout << "Edges in MST: ";
    for (auto p : mst_edges) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}

void prims_algo(int n, vector<vector<pair<int,int>>>& adj) {
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    key[0] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u] == true) {
            continue;
        } else {
            visited[u] = true;
        }

        for (auto e : adj[u]) {
            int v = e.first;
            int w = e.second;
            if (visited[v] == false && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int mst_weight = 0;
    vector<pair<int,int>> mst_edges;
    for (int i = 1; i < n; i++) {
        mst_weight += key[i];
        mst_edges.push_back({parent[i], i});
    }

    cout << "Prim MST weight: " << mst_weight << endl;
    cout << "Edges in MST: ";
    for (auto p : mst_edges) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<Edge> edges(m);
    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges (u v weight)" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        adj[edges[i].u].push_back({edges[i].v, edges[i].weight});
        adj[edges[i].v].push_back({edges[i].u, edges[i].weight});
    }

    kruskal_algo(n, edges);
    prims_algo(n, adj);

    return 0;
}

// Kruskal TC=O(E·V)	SC=O(V + E)
// Prim	TC=O(E log V)	SC=O(V + E)