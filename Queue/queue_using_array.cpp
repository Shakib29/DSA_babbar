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
        front=0;
        rear=0;
    }




void enqueue(int x){
if(rear==size-1){
cout<<"queue is full";
}else{
    arr[rear]=x;
    rear++;
}
}

int  dequeue(){
    if(front==rear){
        cout<<"queue is empty";
        return-1;
    }else{
        int ans=arr[front];
        arr[front]=-1;
        front++;
        if(front==rear){
            front=0;
            rear=0;
        }
    
    return ans;
    }
}
void isempty(){
    if(front==rear){
        cout<<"queue is empty";
    }else{
        cout<<"not empty";
    }
}
int onfront(){
    if(front==rear){
        return -1;
    }
    else{
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