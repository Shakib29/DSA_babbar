#include<iostream>
#include<stack>
using namespace std;

int findmincost(string str){
     //odd condition 
     if(str.length()%2==1){
        return -1;
     }

     //remove valid brackets
     stack <char> s;
     for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='{'){
            s.push(ch);
        }
        else{
            //matlab ch ek } hai
            if(!s.empty()&&s.top()=='{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
     }
     //stack contains invalid expressionn
     int a=0,b=0;
     while(!s.empty()){
        if(s.top()=='{'){
            b++;
        }else{
            a++;
        }
       s.pop();
     }
     int ans=(a+1)/2+(b+1)/2;
     return ans;
}
int main(){
    string exp="}}}}";
    int ans=findmincost(exp);
     cout<<endl<<ans;

}