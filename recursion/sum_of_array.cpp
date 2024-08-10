#include <iostream>
using namespace std;

int cal(int arr[],int n){
 if(n==0){
    return 0;
 }
 
    return arr[0]+cal(arr+1,n-1);
 
}

int main(){
    int arr[5];
    cout<<"enter array elements"<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];

    }
   int sum=cal(arr,5);
   cout<<sum;
    
}