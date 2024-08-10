#include<iostream>
using namespace std;
int insertion_sort(int arr[],int n){
int key;
for(int j=1;j<n;j++){
    key=arr[j];
    int i=j-1;
    while(i>=0&&arr[i]>key){
        arr[i+1]=arr[i];
        i--;
    }
    arr[i+1]=key;
}


}


int main(){
    int arr[5]={2,3,9,5,6};
    insertion_sort(arr,5);
      for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}