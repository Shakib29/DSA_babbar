#include<iostream>
using namespace std;
bool binarysearch(int arr[][4],int rows,int col,int target){
int start=0;
int end=(rows*col)-1;
int mid=start+(end-start)/2;
while(start<=end){
  int element=arr[mid/col][mid%col];
  if(element==target){
   return true;
  }
 if(element>target){
    end=mid-1;
 }else{
    start=mid+1;
 }
mid=start+(end-start)/2;
}
 
return false;
}


int main(){
    int arr[3][4];
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cout<<"Enter Target elemnt"<<endl;
    cin>>target;
    if(binarysearch(arr,3,4,target)){
        cout<<"element is present ";
    }else{
         cout<<"element is not present ";
    }
}