#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top;
    int size;

    stack(int size)
    {
        this->size=size;
        arr=new int[size];    //dynamic array
        top=-1;
    }

void push(int element){
 if(size-top>1){
  top++;
 arr[top]=element;
 }else{
    cout<<"stack is full"<<endl;
 }
}

void pop(){
if(top>=0){

    top--;
}else{
    cout<<"stack is empty"<<endl;
}
}
int peek(){
    if(top>=0){
        return arr[top];
    }else{
            cout<<"stack is empty"<<endl;
            return -1;
    }
}
bool isempty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}
};
int main(){
stack st(5);
st.push(4); 
cout<<st.peek()<<endl;

st.push(3); 
cout<<st.peek()<<endl;

st.push(7); 
cout<<st.peek()<<endl;

st.push(8); 
cout<<st.peek()<<endl;

st.push(9); 
cout<<st.peek()<<endl;

st.push(10);
cout<<st.peek()<<endl;

cout<<st.peek()<<endl;




}
