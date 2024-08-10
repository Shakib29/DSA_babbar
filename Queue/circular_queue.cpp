#include<iostream>
#include<queue>
using namespace std;

class myqueue{
    
    int size;
    int *arr;
    int front ;
    int rear;
    public:
    myqueue(){
        size=10000;
        arr=new int[size];
        front=-1;
        rear=-1;
    }




void enqueue(int x){
if((front==0&&rear==size-1)||(rear==(front-1)%(size-1))){
cout<<"queue is full";
}else if(front==-1){    //first element to insert
    front=rear=0;
    arr[rear]=x;
}else if(rear==size-1&&front!=0){
    rear=0;
     arr[rear]=x;
}else{
    rear++;
     arr[rear]=x;
}
}

int  dequeue(){
    if(front==-1){
        cout<<"queue is empty";

    }
    arr[front]=-1;
    if(front==rear){
     front=rear=-1;
    }else if(front==size-1){
        front=0;
    }else{
        front++;
    }
}

    bool isempty() {
        return front == -1;
    }

    int onfront() {
        if (isempty()) {
            return -1;
        } else {
            return arr[front];
        }
    }

};
int main(){
   myqueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.onfront() << endl; // Output: 1
    q.dequeue();
    cout << q.onfront() << endl; // Output: 2
    q.dequeue();
    cout << q.onfront() << endl; // Output: 3
    q.dequeue();
         
    return 0;
}