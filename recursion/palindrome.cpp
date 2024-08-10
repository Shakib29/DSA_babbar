#include <iostream>
using namespace std;

bool palindrome(string str,int i,int j){
    if(i>j){
        return true;
    }
   if(str[i]!=str[j]){
    return false;
   }else{
    return palindrome(str,++i,--j);
   }

    
}
int main(){
string name="abba";
bool ans=palindrome(name,0,name.length()-1);
if(ans){
cout<<"palindrome";
}else{
    cout<<"not a palindrome";
}

}