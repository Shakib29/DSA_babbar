#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v){
 int s=0,e=v.size()-1;
 while(s<e){
swap(v[s],v[e]);
s++;
e--;
 }
 return v;
} 
void print(vector<int> a){
     for(int i=0;i<a.size();i++){
        cout<<a[i];
    }
}
int main(){
    vector<int> a;
    a.push_back(9);
    a.push_back(2);
    a.push_back(5);
    a.push_back(7);
    a.push_back(3);
    vector<int> ans=reverse(a);
    
   print(ans);




}