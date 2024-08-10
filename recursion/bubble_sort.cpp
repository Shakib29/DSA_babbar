#include <iostream>
using namespace std;


int print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void bubblesort(int arr[],int n){
    if(n==0||n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
       if(arr[i]>arr[i+1])
        swap(arr[i],arr[i+1]);
    }
    bubblesort(arr,n-1);
}
int main(){
    int arr[6]={5,65,64,2,12,4};
   int n=6;
    bubblesort(arr,n);
    print(arr,n);

}