#include<iostream>
using namespace std;
int main(){
    int sum=0;
    int product=1;
    int n;
    cout<<"enter n";
    cin>>n;
    while (n!=0)
    {
        int digit=n%10;
        sum+=digit;
        product*=digit;
        n=n/10;
    }
    cout<<sum<<" "<<product;
}