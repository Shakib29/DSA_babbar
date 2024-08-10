#include<iostream>
using namespace std;

void rotate(int arr[],int n,int k){
    int temp[6];
    for(int i=0;i<n;i++){
        temp[(i+k)%n]=arr[i];
    }
   for(int i=0;i<6;i++){
        cout<<temp[i];
    }

}
    
int main(){
    int arr[6]={0,1,0,3,2,0};
    int k;
    cout<<"enter how many places to rotate";
    cin>>k;
    rotate(arr,6,k);
   
}
