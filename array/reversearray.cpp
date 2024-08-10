#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;

}
 int reverse(int arr[],int n){
    int start=0;
    int end=n-1;
  while(start<end){
    swap(arr[start],arr[end]);
    start++;
    end--;
  }
 }
 
int main(){
 int n;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    reverse(arr,n);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;

    }

  return 0;
}