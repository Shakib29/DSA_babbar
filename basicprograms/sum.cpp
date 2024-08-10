#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    int sum=0,i=0;
    
    while (i<=n)
    {
        if(i%2==0){
        sum=sum+i;}
        i++;
    }
    cout<<"sum of "<<n<<" is "<<sum;
    
}

