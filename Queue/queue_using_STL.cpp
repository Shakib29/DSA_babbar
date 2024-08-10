#include<iostream>
#include<queue>
using namespace std;
int main(){
queue <int> q;
q.push(3);
q.push(4);
q.push(5);
q.push(6);

q.pop();

cout<<"size of queue "<<q.size()<<endl;
cout<<"front of queue is "<<q.front();


}