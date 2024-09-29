#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> distance(n + 1, INT32_MAX); // Use INT_MAX for better readability
    distance[src] = 0;  

    // Relax edges n-1 times
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (distance[u] != INT32_MAX && (distance[u] + weight) < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];
        if (distance[u] != INT32_MAX && (distance[u] + weight) < distance[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return {}; // Or handle it as per your requirements
        }
    }

    return distance;
}
