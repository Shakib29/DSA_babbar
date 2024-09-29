#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main(){
  unordered_map<string,int> m;

  //insertion
  //1
  pair<string,int> p=make_pair("shakib",75);
  m.insert(p);

  //2
  pair<string,int> pair2("madrid",15);
    m.insert(pair2);

  //3
  m["barcelona"]=5;

  //searching
  //1 
  cout<<m["madrid"]<<endl;
  //2
  cout<<m.at("barcelona")<<endl;

  //imp 
  // cout<<m.at("unknownkey");
  // cout<<m["unknownkey"]<<endl;

  //farak hai dono me
  cout<<m["unknownkey"]<<endl;
  cout<<m.at("unknownkey")<<endl;

  cout<<m.size()<<endl;

  //check presence
  cout<<"madrid"<<endl;

  //erase
  m.erase("barcelona");
  cout<<m.size()<<endl;

  //traverse
  //1
  // for(auto i:m){
  //   cout<<i.first<<" "<<i.second<<endl;
  // }
  //2   iterator
  unordered_map<string,int> :: iterator it=m.begin();

  while(it !=m.end()){
    cout<<it->first<<" "<<it->second<<endl;
  }
}