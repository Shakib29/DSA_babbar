#include<iostream>
using namespace std;
int occ(int arr[],int n){
    int s=0;
    int e=n-1;
   int mid;
    while(s<e){
         mid=s+(e-s)/2;
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return s;
}

int main(){
    int arr[5]={1,2,3,2,1};
   int peakIndex=occ(arr,5);
      cout << "Peak element is at index: " << peakIndex << " and its value is " << arr[peakIndex] << endl;
    return 0;
}