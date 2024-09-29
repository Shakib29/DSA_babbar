#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    unordered_map<int, list<int>> adj;
    
    // Build the adjacency list
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS initialization
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    // BFS traversal
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        
        for (auto neighbour : adj[front]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);

                // Stop the BFS if we reach the target node
                if (neighbour == t) {
                    break;
                }
            }
        }
    }

    // Reconstruct the path
    vector<int> ans;
    if (visited[t]) {
        int curr = t;
        while (curr != -1) {
            ans.push_back(curr);
            curr = parent[curr];
        }
        reverse(ans.begin(), ans.end());
    }
    
    return ans;
}
