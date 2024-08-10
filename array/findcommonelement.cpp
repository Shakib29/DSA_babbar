#include<iostream>
using namespace std;
int main(){
  int arr1[]={1,3,4,8};
  int arr2[]={2,5,6,7};
 int n=3;
 for(int i=0;i<n;i++){
    int element=arr1[i];
    for(int j=0;j<n;j++){
    if (element==arr2[j]){
        cout<<element;
        exit(0);
    }

    }
    



 }
 cout<<" no common element is present";


}

