#include<iostream>
using namespace std;
void merge(int arr1[],int n,int arr2[],int m,int arr[]){
    int i=0;
    int j=0;
    int k=0;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
          arr[k]=arr1[i];
          k++;
          i++;
        }else{
              arr[k]=arr2[j];
          k++;
          j++;
        }
    }
    while(i<n){           //if a array is grater in size than other 
        arr[k]=arr1[i];
        k++;
        i++;
    }
     while(j<m){               //if a array is grater in size than other
        arr[k]=arr2[j];
        k++;
        j++;
    }
}
void print(int arr[],int n){
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr1[4]={1,3,4,7};
    int arr2[4]={2,4,6,8};
   int  arr[8]={0};
    merge(arr1,4,arr2,4,arr);
     print(arr,8);
}