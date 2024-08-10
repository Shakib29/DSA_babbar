#include<iostream>
#include <algorithm> 
using namespace std;
bool ispossible(int stalls[],int n,int k,int mid)
{
    int cowcount=1;
    int lastpos=stalls[0];
    for(int i=0;i<n;i++){
        if(stalls[i]-lastpos>=mid){
            cowcount++;
            if(cowcount==k){
                return true;
            }
            lastpos=stalls[i];
        }
    }
     return false;
}
int aggcow(int stalls[],int n,int k){
    sort(stalls, stalls + n);
    int s=0;
    int maxi=-1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,stalls[i]);
    }
    int e=maxi;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(ispossible(stalls,5,k,mid)){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int stalls[5]={4,2,1,3,6};
    int k=2;
    cout<<aggcow(stalls,5,k);
}