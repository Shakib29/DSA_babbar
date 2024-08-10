#include<iostream>
#include<stack>
#include<queue>
using namespace std;
queue<int> rev(queue<int> q,int k)
{
    stack<int> s;
    
   for(int i=0;i<k;i++){
    int val=q.front();
    q.pop();
    s.push(val);
   }

   while(!s.empty()){
    int val=s.top();
    s.pop();
    q.push(val);
   }
   // fetch (n-k) element form queue ans push back 
   int t=q.size()-k;
   while(t--){
    int val=q.front();
    q.pop();
    q.push(val);
   }
    return q;
}
int main(){
    queue <int> q;
    q.push(1);
        q.push(2);

    q.push(3);
    q.push(4);
    queue <int> ans=rev(q,2);
    while(!ans.empty()){
      cout<<ans.front();
      ans.pop();
    }
}