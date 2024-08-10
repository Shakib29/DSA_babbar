#include <iostream>
using namespace std;


void cal(int n){
    if(n==0){                        //base case
        return ;
    }
        cout<<n<<" ";             //processing part
         cal(n-1);            // recursive relation
    
}
int main(){
    int n;
    cout<<"enter a number :"<<endl;
    cin>>n;
    cal(n);
    

}