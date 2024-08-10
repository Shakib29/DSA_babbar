#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool issafe(int x,int y,int n,vector<vector<int>> &visited,vector<vector<int>> &m){
    if((x>=0&&x<n)&&(y>=0&&y<n)&&m[x][y]==1&&visited[x][y]==0){
      return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> &m,int n,vector<string>& ans,int x,int y,vector<vector<int>> &visited , string path)
{
 //base condition
 if(x==n-1&&y==n-1){
    ans.push_back(path);
    return;
 }
 visited[x][y]=1;

 //we have four choices=>D,L,R,U

 //down
 int newx=x+1;           
 int newy=y;
 if(issafe(newx,newy,n,visited,m)){
    path.push_back('D');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();

 }
 //left
 newx=x;
 newy=y-1;
 if(issafe(newx,newy,n,visited,m)){
    path.push_back('L');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();

 }
 //right
 newx=x;
 newy=y+1;
 if(issafe(newx,newy,n,visited,m)){
    path.push_back('R');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();

 }
 //up
 newx=x-1;
 newy=y;
 if(issafe(newx,newy,n,visited,m)){
    path.push_back('U');
    solve(m,n,ans,newx,newy,visited,path);
    path.pop_back();

 }
  visited[x][y]=0;
}

vector<string> findpath(vector<vector<int>> &m,int n){
int srcx=0;
int srcy=0;
vector<string> ans;
vector<vector<int>> visited =m;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        visited[i][j]=0;
    }
}
string path="";
solve(m,n,ans,srcx,srcy,visited,path);
return ans;

}
int main() {
    vector<vector<int>> m = { {1, 0, 0, 0},
                              {1, 1, 0, 1},
                              {0, 1, 0, 0},
                              {1, 1, 1, 1} };
    int n = 4;
    vector<string> result = findpath(m, n);
    for (const string& s : result) {
        cout << s << " ";
    }
    return 0;
}