#include<iostream>
#include<stack>
using namespace std;

void solve(stack <int> &s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    solve(s,x);
    s.push(num);
}

stack <int> push_at_bottom(stack <int> &s,int x){
solve(s,x);
return s;
}

int main(){
int element=9;
stack <int> s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
push_at_bottom(s,element);
while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
}
}