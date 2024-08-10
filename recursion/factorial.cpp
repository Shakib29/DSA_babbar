#include <iostream>
using namespace std;


int cal(int n){
    if(n==0){
        return 1;
    }else{
        return n*cal(n-1);
    }
}
int main(){
    int n;
    cout<<"enter a number :"<<endl;
    cin>>n;
    int ans=cal(n);
    cout<<ans;

}