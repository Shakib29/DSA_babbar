#include<iostream>
using namespace std;
 int getmin(int arr[],int n){
    int min=INT32_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
 }

 int getmax(int arr[],int n){
    int max=INT32_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
 }

int main(){
    int size;
    cout<<"ENTER SIZE OF ARRAY";
    cin>>size;
    int arr[size];
    cout<<"enter array elements";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //  cout<<"printing array elements";
    //  for(int i=0;i<size;i++){
    // cout<<arr[i]<<endl;
    // }
   cout<<"maximum element is :"<<getmax(arr,size)<<endl;
   cout<<"minimum element is :"<<getmin(arr,size);
}