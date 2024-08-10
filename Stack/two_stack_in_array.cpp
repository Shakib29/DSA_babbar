#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    stack(int size)
    {
        this->size=size;
         top1=-1;
         top2=size;
        arr=new int[size];
    }

void push1(int element){
 if((top2-top1)>1){
  top1++;
 arr[top1]=element;
 }else{
    cout<<"stack is full"<<endl;
 }
}

void push2(int element){
 if((top2-top1)>1){
  top2--;
 arr[top2]=element;
 }else{
    cout<<"stack is full"<<endl;
 }
}

int pop1(){
if(top1>=0){
    int ans=arr[top1];
    top1--;
    return ans;
}else{
    cout<<"stack is empty"<<endl;
    return -1;
}
}

int pop2(){
if(top2<size){
    int ans=arr[top2];
    top2++;
    return ans;
}else{
    cout<<"stack is empty"<<endl;
    return -1;
}
}

int peek1(){
    if(top1>=0){
        return arr[top1];
    }else{
            cout<<"stack is empty"<<endl;
            return -1;
    }
}
int peek2(){
    if(top2<size){
        return arr[top2];
    }else{
            cout<<"stack is empty"<<endl;
            return -1;
    }
}

bool isempty1(){
    if(top1==-1){
        return 1;
    }else{
        return 0;
    }
}

bool isempty2(){
    if(top2==size){
        return 1;
    }else{
        return 0;
    }
}
 
            
};
int main(){
stack st(5);
st.push1(5);
st.push1(4);
st.push1(3);
st.push2(1);
st.push2(2);
int ans=st.peek1();
cout<<ans<<endl;
cout<<st.pop1()<<endl;
cout<<st.peek1();

}
