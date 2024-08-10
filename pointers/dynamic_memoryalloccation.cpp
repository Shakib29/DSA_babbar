#include<iostream>
using namespace std;

    
    // int *ptr=new int[5] ;
    // *ptr=8;
    // ptr=ptr+2;
    // *ptr=6;
    // cout<<*ptr<<endl;
    // ptr=ptr-2;
    // cout<<*ptr;
    // cout<<sizeof(ptr);

// heap wala hai dynamic memory allocation and stack wala hai static memory allocation




int getsum(int *arr,int n){
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
  }
  return sum;
}

int main(){
    int n;
    cout<<"enter length of array"<<endl;
    cin>>n;
    int *arr=new int [n];
    cout<<"Enter elements of array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // cout<<endl<<"Printing array elements"<<endl;
    //  for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    int ans=getsum(arr,n);
    cout<<ans;
     delete[] arr;
}