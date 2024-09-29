#include<iostream>
#include<conio.h>
#include<queue>
using namespace std;
class heap{
  public:
  int arr[100];
  int size=0;
  heap(){
    arr[0]=-1;
    size=0;

  }
  void insert(int val){               //max heap
  size=size+1;
  int index=size;
  arr[index]=val;

  while(index>1){
int parent=index/2;

if(arr[parent]<arr[index]){
  swap(arr[parent],arr[index]);
  index=parent;
}else{
  return;
}
  }
  }

  void deletion(){
    if(size==0){
      cout<<"nothing to delete";
    }
    //1)put last element to 1st node
    arr[1]=arr[size];           
            //delete last node
   size=size-1;

   //take root node to its correct position
   int i=1;
   while(i<size){
     int leftindex=2*i;
     int rightindex=(2*i)+1;
     if(leftindex<size&&arr[i]<arr[leftindex]){
      swap(arr[i],arr[leftindex]);
      i=leftindex;
     }
     else if(rightindex<size&&arr[i]<arr[rightindex]){
      swap(arr[i],arr[rightindex]);
      i=rightindex;
     }else{
      return;
     }
   }

  }
  int printheap(){
  for(int i=1;i<size;i++){   //0th index should not be use
    cout<<arr[i]<<endl;
  }
  }
};
int main(){
heap h; 
h.insert(55);
h.insert(54);
h.insert(53);
h.insert(50);
h.insert(52);
h.printheap();
cout<<endl;
h.deletion();
h.printheap();

//max heap
priority_queue<int> pq;
pq.push(5);
pq.push(7);
cout<<"top of max heap "<<pq.top()<<endl;

//min heap
priority_queue<int ,vector<int>,greater<int> > minheap;
minheap.push(3);
minheap.push(1);
cout<<"top of min heap "<<minheap.top();



}