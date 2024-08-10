#include<iostream>
using namespace std;

int binarysearch(int arr[],int key,int n){
    int left=0,right=n-1;
    int mid=left+(right-left/2);
    while(left<=right){
  
  if(arr[mid]==key){
    return mid;
  }else if(arr[mid]>key){           //left part me jana hai
 right=mid-1;
  }else{
    left=mid+1;
  }
  mid=left+(right-left/2);

    }
    return -1;

}
int main(){
   int arr[7]={1,2,3,4,5,6,7};
  int index= binarysearch(arr,4,7);
  cout<<"index of 7 is "<<index;
}