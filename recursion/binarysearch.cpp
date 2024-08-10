#include <iostream>
using namespace std;


int print(int arr[],int s,int e){
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
bool binarysearch(int arr[],int s,int e,int k){
    cout<<endl;
    print(arr,s,e);
   if(s>e){
    return false;
   }
   int mid=s+(e-s)/2;
   if(arr[mid]==k){
    return true;
   }

   if(arr[mid]>k){
    return binarysearch(arr,s,mid-1,k);
   }else{
    return binarysearch(arr,mid+1,e,k);
   }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int key=2;
    if(binarysearch(arr,0,4,key)){
        cout<<"element is present";
    }else{
        cout<<"element is not present";
    }

}