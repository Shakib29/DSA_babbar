#include<iostream>
using namespace std;
  char lowercase(char ch){
   if(ch>='a'&&ch<='z'){
    return ch;

   }else{
    char temp=ch-'A'+'a';
   }
  }
bool checkpalindrome(char str[],int n)
{
    int s=0;
    int e=n-1;
    while(s<=e){
    if(lowercase(str[s])!=lowercase(str[e])){
      return false;
    }
    
    s++;
    e--;

    }
   return true;
}
int main(){
    char str[20];
    cout<<"Enter a String :"<<endl;
    cin>>str;
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        count++;
    }
     if (checkpalindrome(str, count)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    // cout<<"to lower case "<<lowercase('A');


}