#include<iostream>
#include<stack>
using namespace std;


int main(){
string name="shakib";
stack<char> s;
for(int i=0;i<name.length();i++){
char ch=name[i];
s.push(ch);
}

string ans="";
while(!s.empty()){
    char ch=s.top();
    ans.push_back(ch);
    s.pop();
}

cout<<"Reverse string is "<<ans;

}
