#include<iostream>
#include<stack>
using namespace std;

bool isvalid(string exp){
    stack <char> s;
    for(int i=0;i<exp.length();i++){
        char ch=exp[i];

        //if opening bracket,stack push
        //if closing bracket,stack check and pop

        if(ch=='('||ch=='['||ch=='{'){
            s.push(ch);
        }else{
            //for closing bracket
            if(!s.empty()){
            char top=s.top();
            if((ch==')'&&top=='(')||
               (ch==']'&&top=='[')||
               (ch=='}'&&top=='{')){
             s.pop();
            }else{
                return false;
            }
            }
             else{
                return false;
             }
        }


        
    }
    if(s.empty()){           //kya pata kuch extra ho ya nhi
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string exp="{[()]}";
    if(isvalid(exp)){
        cout<<"it is valid";
    }else{
        cout<<"it is Invalid";
    }


}