#include<iostream>
using namespace std;
int firstoccurence(int arr[],int n,int k){
    int left=0;
    int right=n-1;
    
    int ans=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
    if(arr[mid]==k){
        ans=mid;
        right=mid-1;
    }
    else if(arr[mid]>k){
        right=mid-1;
    }else{
        left=mid+1;
    }
      
    }
    return ans;
    }

int lastoccurence(int arr[],int n,int k){
    int left=0;
    int right=n-1;
    
    int ans=0;
    while(left<=right){
        int mid=left+(right-left)/2;
    if(arr[mid]==k){
        ans=mid;
        left=mid+1;
    }
    else if(arr[mid]>k){
        right=mid-1;
    }else{
        left=mid+1;
    }
      
    }
    return ans;
    }



int main(){
    int arr[7]={1,2,3,3,4,5,6};
    cout<<endl<<firstoccurence(arr,7,3);
   cout<<endl<< lastoccurence(arr,7,3);
   return 0;
}

