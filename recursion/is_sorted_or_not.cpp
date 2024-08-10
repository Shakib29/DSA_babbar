#include <iostream>
using namespace std;

bool cal(int arr[],int n){
    if(n==0||n==1){
        return true;
}else{
  if(arr[0]>arr[1]){
    return false;
  }  else{
    bool ans=cal(arr+1,n-1);
    return ans;
  }
}
}

int main(){
    int arr[10];
    cout<<"enter array elements"<<endl;
    for(int i=0;i<10;i++){
        cin>>arr[i];

    }
    if(cal(arr,10)){
        cout<<"array is sorted"<<endl;
    }else{
        cout<<"array is not sorted"<<endl;
    }
    
}