#include<iostream>
#include<stack>
using namespace std;

void sortedinsert(stack <int> &s,int num){
 if(s.empty()||(!s.empty()&&s.top()<num)){
    s.push(num);
    return;
 }
 // Recursive case:
    // 1. Pop the top element of the stack
    // 2. Recursively call sortedinsert to insert num in the correct position
    // 3. Push back the popped element after the recursive call to maintain ord
 int n=s.top();
 s.pop();
 sortedinsert(s,num);
 s.push(n);

}

void sort_stack(stack <int> &s){
    //base case
    if(s.empty()){                  //jab tak stack khali nhi hota nikalte raho
        return;
    }
    int num=s.top();
    s.pop();
    sort_stack(s);

    sortedinsert(s,num);
}

int main(){
stack <int> s;
s.push(1);
s.push(-9);
s.push(3);
s.push(-4);
sort_stack(s);
while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
}
}