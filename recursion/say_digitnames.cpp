#include <iostream>
using namespace std;


void cal(int n,string arr[]){
    
   if(n==0){
   return;
   }

   
    int digit=n%10;
    n=n/10;
   

    cal(n,arr);
 cout<<arr[digit]<<" ";
   
}
int main(){
    int n;
    string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    cout<<"enter a number :"<<endl;
    cin>>n;
    cal(n,str);

    // cout<<ans;

}