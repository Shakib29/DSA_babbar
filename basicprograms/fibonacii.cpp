#include<iostream>
using namespace std;
int main(){
    int a=0,b=1;
    
    int n;
    cout<<"Enter range of fibonacci series :";
    cin>>n;
    cout<<a<<" "<<b<<" ";
    for(int i=0;i<=n;i++){
        int nexnum=a+b;
        cout<<nexnum<<" ";
        a=b;
        b=nexnum;
        
    }
    
}