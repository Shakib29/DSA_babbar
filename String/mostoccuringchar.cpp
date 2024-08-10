#include<iostream>
using namespace std;

char mostoccur(string s){
 int arr[26]={0};
 for(int i=0;i<s.length();i++){
    char ch=s[i];
    int number =0;
    number=ch-'a';
    arr[number]++;

 }

 int maxi=-1,ans=0;
 for(int i=0;i<26;i++){
    if(maxi<arr[i]){
       ans=i;
        maxi=arr[i];
    }
 }
 char finalans='a'+ans;
 return finalans;




}


int main(){
    char str[20];
    cout<<"enter a string";
    cin.getline(str,20);
    
     cout << "character with most occurence: " << mostoccur(str) << endl;

    return 0;
}