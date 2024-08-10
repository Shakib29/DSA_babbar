#include <iostream>
using namespace std;


int cal(int base,int power){
    if(power==0)
    return 1;
    else{
         return base*cal(base,power-1);
    }
}
int main(){
    int base,power;
    cout<<"enter base and power :"<<endl;
    cin>>base>>power;
    int ans=cal(base,power);
    cout<<ans;

}