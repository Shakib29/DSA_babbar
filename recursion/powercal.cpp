#include <iostream>
using namespace std;
int cal(int b,int e){
    if(e==0){
        return 1;
    }
    if(e==1){
        return b;
            
    }
     int ans= cal(b,e/2) ;     
     if(e%2==0){
        return ans*ans;
     } else{
        return b*ans*ans;
     }
}

int main(){
    int base,expo;
    cout<<"enter base and exponential";
    cin>>base>>expo;
    int ans=cal(base,expo);
     cout << base << "^" << expo << " = " << ans << endl;

    return 0;
}