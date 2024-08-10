#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.pop();
    cout<<s.top()<<endl;
    if(s.empty()){
        cout<<"empty stack"<<endl;
    }else{
         cout<<" not empty stack"<<endl;
    }
    cout<<s.size();

}