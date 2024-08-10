#include<iostream>
using namespace std;

bool linearsearh(int arr[],int n,int key){
 for(int i=0;i<n;i++){
    if(arr[i]==key){
        return 1;
    }
 }

  return 0;
}

int main(){
 int n;
    cout<<"enter size of array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    int key;
    cout<<"enter element to be search ";
    cin>>key;
    int result=linearsearh(arr,n,key);
    if(result){
        cout<<"element is present";
    }else{
        cout<<"element is not present";
    }
}