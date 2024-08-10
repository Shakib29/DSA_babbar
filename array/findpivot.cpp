#include<iostream>
using namespace std;

int pivot(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid;
    while(s<e){
        mid=s+(e-s)/2;
        if(arr[mid]>arr[0]){
            s=mid+1;
        }
        else{
                e=mid;
            }
        
            }
            return s;
}
int main(){
    int arr[5]={8,10,17,1,3};
    cout<<"pivot is "<<pivot(arr,5);
}