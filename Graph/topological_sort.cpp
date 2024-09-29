#include <bits/stdc++.h> 

using namespace std;

void toposort(int node, unordered_map<int, bool> &visited,
              unordered_map<int, list<int>> &adj, stack<int> &s) {
    visited[node] = true;
    
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            toposort(neighbour, visited, adj, s);
        }
    }
    
    // Push the node onto the stack after exploring all its neighbours
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    
    // Create adjacency list
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    
    // Prepare for DFS
    unordered_map<int, bool> visited;
    stack<int> s;
    
    // Call DFS for all nodes
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            toposort(i, visited, adj, s);
        }
    }

    // Retrieve the topological order
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}
