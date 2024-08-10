#include <iostream>
using namespace std;

void reverse(string& str,int i,int j){
    if(i>j){
        return;
    }
    swap(str[i],str[j]);
    reverse(str,++i,--j);

    
}
int main(){
string name="shakib";
reverse(name,0,5);
cout<<name;
}