#include<iostream>
#include<stack>
using namespace std;

bool redundunct(string &s){
    stack <char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'){
         st.push(ch);
        }else{
            //ch ya to ')' ya to koi variable hai
        }
        if(ch==')'){
            bool isredundunt=true;
            while(st.top()!='('){
                char top=st.top();
                if(top=='+'||top=='-'||top=='*'||top=='/'){
                isredundunt=false;
                }
                st.pop();              //ye koi operator nikal sakega
            }
            if(isredundunt==true){
             return true;
            }
            st.pop();             //ye koi bracket jo uper select kiya hai '(' nikal sakega
        }
    }
    return false;
}


int main(){
    string exp="((a+b)-(c-d))";
    redundunct(exp);
     if(redundunct(exp)){
        cout<<"it is redundunct";
    }else{
        cout<<"it is not redundunct";
    }

}