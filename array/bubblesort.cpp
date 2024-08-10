#include<iostream>
using namespace std;
int bubble_sort(int arr[],int n){
    bool swapped=false;
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            swapped=true;
        }
    }
  if (swapped==false){
    break;
  }
}

}

int main(){
    int arr[5]={2,3,9,5,6};
    bubble_sort(arr,5);
      for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}