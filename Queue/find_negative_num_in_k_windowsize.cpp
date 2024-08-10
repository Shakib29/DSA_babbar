#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector <long long> find_negative(long long a[],long long int n,long long int k){
     deque <long long int> dq;
     vector <long long> ans;

     //process first k windows'
     for(int i=0;i<k;i++){
        if(a[i]<0){
            dq.push_back(i);
        }
     }
     //store anwer of first k windowa size
     if(dq.size()>0){
        ans.push_back(a[dq.front()]);
     }else{
        ans.push_back(0);
     }
      //process for remaining windows
      for(int i=k;i<n;i++){
        //removal
        if(!dq.empty()&&i-dq.front()>=k){
            dq.pop_front();
        }
        //addition
        if(a[i]<0){
            dq.push_back(i);
        }

        
     //store anwer of first k windowa size
     if(dq.size()>0){
        ans.push_back(a[dq.front()]);
     }else{
        ans.push_back(0);
     }

      }
      return ans;
}

int main(){
     long long a[] = {-8, 3, -6, 4};
    vector<long long> result = find_negative(a, 4, 2);

    for(long long x : result) {
        cout << x << " ";
    }

    return 0;
}