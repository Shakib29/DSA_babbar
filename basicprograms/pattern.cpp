#include<iostream>
using namespace std;
int main(){
   int n,i,j,count=1;
   cout<<"enter number";
   cin>>n;
   for(i=1;i<=n;i++){
    // int value=i;
    char c='A'+n-i;
    for(j=1;j<=i;j++){
        
      
         cout<<c;
         c++; 
        // value++;
    }
    cout<<endl;

   }
}