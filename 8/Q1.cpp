/*
We have to compute the shortest circular path i.e. closed route (same initial and final node).
We thus use Dijkstra’s Algorithm.

Remove an edge between u and v temporarily.
Find the shortest path from u to v.
Add that path length to the original edge between u and v.
Keep track of the min cycle length found.

*/
// run using:
// a.exe < assign8_input.txt > output.txt
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

// Dijkstra's algorithm: shortest path from source to destination
// Skips the edge (skip_u, skip_v) temporarily
int dijkstra_skip(int n, int source, int destination,
                  vector<vector<pair<int,int>>> &adj,
                  int skip_u, int skip_v) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if(d > dist[u]) continue;
        if(u == destination) return dist[u]; // early exit

        for(auto &[v, w] : adj[u]) {
            // Skip the edge temporarily
            if((u == skip_u && v == skip_v) || (u == skip_v && v == skip_u))
                continue;

            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return INF;
}

int main() {
    int t;
    cin >> t; // number of test cases
    while(t--) {
        int m;
        cin >> m; // number of edges

        vector<Edge> edges(m);
        int maxNode = 0;

        for(int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            maxNode = max(maxNode, max(edges[i].u, edges[i].v));
        }

        int n = maxNode;
        vector<vector<pair<int,int>>> adj(n+1);

        // Build adjacency list
        for(auto &e : edges) {
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }

        int ans = INF;

        // For each edge, skip it and find shortest path between its endpoints
        for(auto &e : edges) {
            int shortest = dijkstra_skip(n, e.u, e.v, adj, e.u, e.v);
            if(shortest != INF)
                ans = min(ans, shortest + e.w); // total cycle length
        }

        cout << ans << "\n";
    }

    return 0;
}
