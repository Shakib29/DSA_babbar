#include<iostream>
#include<stack>
using namespace std;

void solve(stack <int> &s,int n,int count){
    //base case
    if(count==n/2){
        s.pop();
        return;
    }
    int num=s.top();
    s.pop();
    solve(s,n,count+1);       //recursive call
    s.push(num);
}

void deletemiddleelement(stack <int> &s,int n){
int count=0;
solve( s,n,count);

}

int main(){
    stack <int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    //to delete element 3
  int n=s.size();
    deletemiddleelement(s, n);

    // Print the stack after deleting the middle element
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;

}