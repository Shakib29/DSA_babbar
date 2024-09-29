#include <vector>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>& edges) {
    // Create an adjacency list with n empty vectors
    vector<vector<int>> adj(n);

    // Fill the adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Add the edge to the adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    return adj;
}
