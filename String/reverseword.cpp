#include<iostream>
using namespace std;

    char reversewords(char str[],int s,int e){
while(s<e){
char temp=str[s];
str[s]=str[e];
str[e]=temp;
s++;
e--;


}

    }



char reverseeachword(char str[]){
    int s=0,e=0;
    while(str[e]!='\0'){
        while(str[e]!=' '&&str[e]!='\0'){
           e++;
        }
        reversewords(str,s,e-1);
        if(str[e]==' '){
            e++;
        }
        s=e;
    }

}



int main(){
    char str[20];
    cout<<"enter a string";
    cin.getline(str,20);
    reverseeachword(str);
     cout << "String with each word reversed: " << str << endl;

    return 0;
}
