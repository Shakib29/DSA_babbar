#include<iostream>
using namespace std;
int selection_sort(int arr[],int n){
    int minindex;
    for(int i=0;i<=n-1;i++){
         minindex=i;
        for(int j=i+1;j<=n;j++){
            if(arr[j]<arr[minindex])
            minindex=j;
        }
    
    swap(arr[minindex],arr[i]);
    }
    
}
int main(){
    int arr[5]={2,3,9,5,6};
    selection_sort(arr,5);
      for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}