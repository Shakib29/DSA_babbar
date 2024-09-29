//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        // step 1
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        // step2
        for(int i=k;i<=arr.size()-1;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        // step3
        int ans=pq.top();
        return ans;
        
    }
};
