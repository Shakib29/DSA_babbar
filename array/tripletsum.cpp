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
            for(int k=j+1;k<n;k++){
            if (arr[i]+arr[j]+arr[k]==s){
              cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k];

                //  ans=temp;
                //  int sort(ans);
                //  cout<<temp<<temps;
            }
            }
        }
    }
    
}