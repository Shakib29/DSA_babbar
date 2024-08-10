#include<iostream>
using namespace std;

string replace(string s){
  string temp="";
for(int i=0;i<s.length();i++){
 if(s[i]==' '){
  temp.push_back('@');
  temp.push_back('4');
  temp.push_back('0');

 }else{
 temp.push_back(s[i]);
 }

}

return temp;
}




int main(){
    char str[20];
    cout<<"enter a string";
    cin.getline(str,20);
    
     cout << "character with most occurence: " << replace(str) << endl;

    return 0;
}