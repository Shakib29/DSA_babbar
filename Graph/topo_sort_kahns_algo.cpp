//using bfs
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adj
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
      int u=edges[i][0];
      int v=edges[i][1];
     adj[u].push_back(v);
    }

    //create indegree
    vector<int> indegree(v);
   for(auto i:adj){
        for(auto j:i.second){
          indegree[j]++;
        }
   }

   //insert element of indegree=0 in queue
   queue<int> q;
   for(int i=0;i<v;i++){
     if(indegree[i]==0){
       q.push(i);
     }
   }

   //bfs
   vector<int> ans;

   while(!q.empty()){
     int front=q.front();
     q.pop();

     ans.push_back(front);
     for(auto neighbour: adj[front]){
       indegree[neighbour]--;
       if(indegree[neighbour]==0){
         q.push(neighbour);
       }
     }
   }
   return ans;
}