#include<iostream>
using namespace std;

int sort(int arr[],int n){
    int i,j=0;
    for(i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

}

int main(){
    int arr[6]={0,1,0,3,2,0};
    sort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i];
    }
}