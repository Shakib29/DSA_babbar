#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    bool isprime =1;
    for(int i=2;i<n;i++){
        if(n%i==0){
            // cout<<"number is not a prime";
            isprime=0;
            break;
        }
    }
    if(isprime==0){
        cout<<"number is not a prime";
    }else{
        cout<<"number is  a prime";
    }
}