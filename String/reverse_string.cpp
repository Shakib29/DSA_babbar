#include<iostream>
using namespace std;

void reverse(char str[],int n){
    int i=0,j=n-1;
    while(i<j){
        swap(str[i],str[j]);
        i++;
        j--;
    }
    
}


int main(){
    char str[20];
    cout<<"enter a string ";
    cin>>str;
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        count++;
    }
  cout<<count<<endl;
    reverse(str,count);
    cout<<endl<<"your reverse name is :"<<str;
}