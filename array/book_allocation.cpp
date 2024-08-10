#include<iostream>
using namespace std;
int ifpossible(int arr[],int n,int m,int mid){
    int pagesum=0;
    int studentcount=1;
    for(int i=0;i<n;i++){
        if(pagesum+arr[i]<=mid){
            pagesum=pagesum+arr[i];
        }else{
          studentcount++;
          if(studentcount>m||arr[i]>mid){
            return false;
          }
          pagesum=arr[i];
        }   
    }
    return true;
}
int bookallo(int arr[],int n,int m){
    int s=0;
    int sum=0;
    for(int i=0;i<n;i++){
     sum+=arr[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(ifpossible(arr,4,m,mid)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int arr[4]={12,34,67,90};
    int m=2;
    int soln=bookallo(arr,4,m);
    cout<<soln;
}