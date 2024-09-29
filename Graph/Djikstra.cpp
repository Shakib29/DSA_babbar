#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int, int>>> adj;
    
    // Building the adjacency list
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // For undirected graph
    }

    vector<int> dist(vertices, INT_MAX); // Initialize distances to INT_MAX
    dist[source] = 0; // Distance to source is 0

    set<pair<int, int>> st; // Set to store {distance, node}
    st.insert(make_pair(0, source));

    while (!st.empty()) {
        auto top = *(st.begin());
        int nodedist = top.first;
        int topnode = top.second;

        st.erase(st.begin());

        // Relaxation step
        for (auto neighbour : adj[topnode]) {
            if ( neighbour.second  + nodedist  < dist[neighbour.first]) {
                // Remove the old record if it exists
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != st.end()) {
                    st.erase(record);
                }
                
                // Update distance
                dist[neighbour.first] = nodedist + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist; // Return the distance vector
}

int main() {
    // Example usage
    int vertices = 5; // Number of vertices
    int edges = 6;    // Number of edges
    vector<vector<int>> vec = {
        {0, 1, 10},
        {0, 2, 5},
        {1, 2, 2},
        {1, 3, 1},
        {2, 1, 3},
        {2, 3, 9},
        {2, 4, 2},
        {3, 4, 4}
    };

    int source = 0; // Starting node
    vector<int> distances = dijkstra(vec, vertices, edges, source);

    // Print distances
    for (int i = 0; i < distances.size(); i++) {
        cout << "Distance from " << source << " to " << i << " is " << distances[i] << endl;
    }

    return 0;
}
