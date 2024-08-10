#include<iostream>
#include<string>
using namespace std;
string substring(string s,string part){
   while(s.length()!=0&&s.find(part)<s.length()){
      s.erase(s.find(part),part.length());

   }

 return s;
}

int main(){
    char str[20],part[10];
    cout<<"enter a string";
    cin.getline(str,20);
    cout<<"enter part"<<endl;
    cin>>part;
     cout << "character left is : " << substring(str,part) << endl;

    return 0;
}