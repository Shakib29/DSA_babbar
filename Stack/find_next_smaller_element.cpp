#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextsmaller(vector<int> &arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
     int curr=arr[i];
     while(s.top()>=curr){
        s.pop();
     }
     ans[i]=s.top();
     s.push(curr);
    }
    return ans;
}

int main(){
vector<int> arr;
arr.push_back(2);
arr.push_back(1);
arr.push_back(4);
arr.push_back(3);
vector<int> arr2=nextsmaller(arr,4);
  std::cout << "Vector elements: ";
    for (int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}