#include<iostream>
using namespace std;
int binarysearch(int arr[],int s,int e,int k){
  
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==k){
            return mid;
        }
        if(arr[mid]>k){
            e=mid-1;
        }
        else {
            s=mid+1;
        }
    }
    return -1;
}

int findpivot(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}
int findpos(int arr[],int n,int k){
    int pivot=findpivot(arr,n);
    if(arr[pivot]<=k&&k<=arr[n-1]){
        return binarysearch(arr,pivot,n-1,k);
    }
    else{
        return binarysearch(arr,0,pivot-1,k);
    }
}
int main(){
    int arr[5]={7,8,9,1,2};
    int k=9;
   int position=findpos(arr,5,k);
   cout<<"pos is "<<position;
}