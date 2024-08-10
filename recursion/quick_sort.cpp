#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}


int partition(int arr[],int s,int e){
    int pivot= arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot)
        count++;
}
   int rightpos=s+count;
   swap(arr[rightpos],arr[s]);

   
  //left aur right part sort karega ye

   int i=s,j=e;
   while(i<rightpos&&j>rightpos){
    while(arr[i]<pivot){
        i++;
    }
    while(arr[j]>pivot){
        j++;
    }
    if(i<rightpos&&j>rightpos){
        swap(arr[i++],arr[j--]);
    }
   }
   return rightpos;
}

void quicksort(int arr[],int s,int e){
    if(s>=e){
      return;
    }
   int p=partition(arr,s,e);
     quicksort(arr,s,p-1);
     quicksort(arr,p+1,e);
}
int main(){
    int arr[5]={2,4,5,6,7};
    int n=5;
    quicksort(arr,0,n-1);
    print(arr,n);
}