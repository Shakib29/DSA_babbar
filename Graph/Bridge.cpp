#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
void dfs(int node,int parent,int &timer,vector<int> &low,vector<int> &disc,vector<bool> &vis,vector<vector<int>> &result, unordered_map<int,list<int>> &adj){
   vis[node]=true;
   disc[node]=low[node]=timer++;
   for(auto nbr: adj[node]){
       if(nbr==parent){
           continue;
       }else if(!vis[nbr]){
           dfs(nbr,node,timer,low,disc,vis,result,adj);
           low[node]=min(low[node],low[nbr]);
           //check if edge is bridge
           if(low[nbr]>disc[node]){
               vector<int> ans;
               ans.push_back(nbr);
               ans.push_back(node);
               result.push_back(ans);
           }
       }else{
           //back edge
           low[node]=min(low[node],disc[nbr]);
       }
   }


                   }




vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
  unordered_map<int,list<int>> adj;
  for(int i=0;i<edges.size();i++){
      int u=edges[i][0];
      int v=edges[i][1];

      adj[u].push_back(v);
        adj[v].push_back(u);

  }
  int timer=0;
  vector<int> low(v);
  vector<int> disc(v);
  int parent =-1;
  vector<bool> vis(v,false);

vector<vector<int>> result;
  for(int i=0;i<v;i++){
      if(!vis[i]){
          dfs(i,parent,timer,low,disc,vis,result,adj);
      }
  }

return result;
}