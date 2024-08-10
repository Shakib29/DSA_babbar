#include<iostream>
using namespace std;

    // without refernce variable

// int update(int i){
//     i++;
    
// }
// int main(){
//     int i=5;
//     cout<<i<<endl;
//     update(i);
//     cout<<i;
// }


//   refernce variable

int update(int &n){
    n++;
    
}
int main(){
    int i=5;
    cout<<i<<endl;
    update(i);
    cout<<i;
}