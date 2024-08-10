#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"enter number of rows";
    cin>>n;
    for(i=1;i<=n;i++){
        
        for(int k=1;k<=n-i;k++){
            cout<<" ";
        }
        for(j=1;j<=i;j++){
           cout<<"*"; 
        }
        cout<<endl;
    }
}
