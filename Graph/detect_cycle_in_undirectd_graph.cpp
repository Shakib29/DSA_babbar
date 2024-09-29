
#include<unordered_map>
#include <queue>
#include<list>
//bfs se....
bool solve(int node,unordered_map<int,bool> &visited,unordered_map<int, list <int>> &adj)
{
  unordered_map<int,int> parent;
  queue<int> q;
  q.push(node);
  visited[node]=true;
  while(!q.empty()){
      int front=q.front();
      q.pop();
    for (auto neighbor : adj[front]) {
      if (visited[neighbor]==true&& neighbor!=parent[front]){
          return true;
      }
      else if(!visited[neighbor]){
      q.push(neighbor);
      visited[neighbor]=true;
      parent[neighbor]=front;
      }
    }
  }
  return false;
}


//dfs se....
bool solvedfs(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list <int>> &adj){
    visited[node]=true;
    for(auto neighbor:adj[node]){
        if(!visited[neighbor]){
            bool cycledeted=solvedfs(neighbor,node,visited,adj);
            if(cycledeted==true){
                return true;
            }
        }else if(neighbor!=parent){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
  for(int i=0;i<m;i++){
      int u=edges[i][0];
      int v=edges[i][1];

   adj[u].push_back(v);
   adj[v].push_back(u);

  }

  unordered_map<int,bool> visited;
  for(int i=0;i<n;i++){
      if(!visited[i]){
          bool ans=solvedfs(i,-1,visited,adj);
          if(ans==1){
              return "Yes";
          }

      }
  }
 return "No";
}

