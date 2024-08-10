#include<iostream>
using namespace std;
int main(){
    char str[20];
    cout<<"Enter your name ";
    cin>>str;
    // str[2]='\0';
    cout<<"Your name is :"<<str;
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        count++;

    }
    cout<<endl<<"your string has "<<count<<" characters";
}