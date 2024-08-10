#include<iostream>
using namespace std;
int main(){
int arr[10]={2,5,6,45,1,22,33,4,56,41};
cout<<"address of first element "<<&arr[0]<<endl;
cout<<"address of first element "<<arr<<endl;
cout<<"address of first element "<<*arr<<endl;    //first element print karega
cout<<"address of first element "<<*(arr+1)<<endl;
int i=2;
cout<<i[arr]<<endl;

int *ptr=&arr[0];
cout<<*ptr<<endl;

cout<<sizeof(ptr);
}

