#include <iostream>
using namespace std;


int cal(int n){
  if(n<0){
    return 0;
  }else if(n==0){
    return 1;
  }else{
    return cal(n-1)+cal(n-2);
  }
}
int main(){
    int n;
    cout<<"enter a number :"<<endl;
    cin>>n;
    int ans=cal(n);
    cout<<ans;

}