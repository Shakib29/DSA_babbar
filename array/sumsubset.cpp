#include<iostream>
using namespace std;
int main(){
int n;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    int s,ans=0;
    cout<<endl<<"enter the sum to find";
    cin>>s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]+arr[j]==s){
                int temp,temps;
                temp=min(arr[i],arr[j]);
                 temps=max(arr[i],arr[j]);
                //  ans=temp;
                //  int sort(ans);
                 cout<<temp<<temps;
            }
        }
    }
    
}