#include<iostream>
using namespace std;
int main(){
    int num=5;
    cout<<num<<endl;
    int *ptr=&num;

    cout<<&num<<endl;
    cout<<ptr<<endl;
    cout<<(*ptr)+1;

    // cout<<"size of integer "<<sizeof(num)<<endl;
    //  cout<<"size of pointer "<<sizeof(ptr)<<endl;


    //  int *p2=0;
    //  cout<<" error "<<*p2;



     int *q=ptr;
     cout<<ptr<<"-"<<q<<endl;
     cout<<*ptr<<"-"<<*q<<endl;
     q=q+1;
     cout<<q<<endl;


     double a=4.18;
     double *d=&a;
     cout<<d<<endl;
     d=d+1;
     cout<<d;



     int e=9;
     int *f=&e;
     *f=10;
     cout<<"value of e:"<<e;

}