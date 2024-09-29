vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

     // Step 1: Create a queue

    queue<int> q;

    

    // Step 2: Choose a source node (assuming 0 here)

    int src = 0;

    q.push(src);

    

    // Step 3: Keep track of visited nodes

    unordered_map<int, bool> visited;

    visited[src] = true;

    

    // Step 4: Perform BFS traversal

    vector<int> result;

    while (!q.empty()) {

        int frontNode = q.front();

        q.pop();

        result.push_back(frontNode);

        

        // Insert neighbors

        for (auto n : adj[frontNode]) {

            if (!visited[n]) {

                q.push(n);

                visited[n] = true;

            }

        }

    }







    

    return result;

}