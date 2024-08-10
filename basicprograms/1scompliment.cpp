#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number:";
    cin>>n;
    int mask=0;
    int m=n;
    while (m!=0)
    {
       mask=(mask<<1)|1;
       m=m>>1;
    }
    int ans=(~n)&mask;
    cout<<ans;
}