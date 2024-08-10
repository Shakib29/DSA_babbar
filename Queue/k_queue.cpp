#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;
class kqueue{
public:
int n;
int k;
int *front;
int *rear;
int *arr;
int *next;
int freespot;

public:
kqueue(int n,int k){
this->n=n;
this->k=k;
front=new int[k];
rear=new int[k];
for(int i=0;i<k;i++){
    front[i]=-1;
    rear[i]=-1;
}
next =new int[n];
for(int i=0;i<n;i++){
    next[i]=i+1;
}
next[n-1]=-1;
arr=new int[n];
freespot=0;
}




void enqueue(int data,int qn){
  //overflow
 if(freespot==-1){
    cout<<"no empty free space "<<endl;
    return;
 }
 //find first free space
 int index=freespot;
 freespot=next[index];
 //check whether first element
 if(front[qn-1]==-1){
    front[qn-1]=index;
 }else{
    //link new with y=the prv element
    next[rear[qn-1]]=index;
 }

 //update next
 next[index]=-1;

 //update rear
 rear[qn-1]=index;

 //push element
 arr[index]=data;
}

int dequeue(int qn){
    if(front[qn-1]==-1){
        cout<<"underflow "<<endl;
        return -1;
    }
    //find index to pop
    int index=front[qn-1];
// front ko next element in that queue point karao
    front[qn-1]=next[index];
    //free slot ko manage karo
    next[index]=freespot;
    freespot=index;
    return arr[index];
}

};
int main(){
    kqueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

   cout<<q.dequeue(1)<<endl;
      cout<<q.dequeue(2)<<endl;

   cout<<q.dequeue(1)<<endl;

   cout<<q.dequeue(1)<<endl;

}