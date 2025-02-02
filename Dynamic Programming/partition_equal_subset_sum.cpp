//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   bool solve(int index,vector<int>& arr,int n,int target ){
       if(index>=n){
           return 0;
       }
       if(target<0){
           return 0;
       }
       if(target==0){
           return 1;
       }
       
       bool include=solve(index+1,arr,n,target-arr[index]);
        bool exclude=solve(index+1,arr,n,target);
        
        return include or exclude;
   }
   
   bool solvemem(int index,vector<int>& arr,int n,int target, vector<vector<int>> dp ){
       if(index>=n){
           return 0;
       }
       if(target<0){
           return 0;
       }
       if(target==0){
           return 1;
       }
       if(dp[index][target]!=-1){
           return dp[index][target];
       }
       
       bool include=solvemem(index+1,arr,n,target-arr[index],dp);
        bool exclude=solvemem(index+1,arr,n,target,dp);
        
        return dp[index][target]= include or exclude;
   }
   
   bool solvetab(vector<int>& arr,int n,int t){
        vector<vector<int>> dp(n+1,vector<int> (t+1,0));
        for(int i=0;i<=n;i++){
             dp[i][0]=1;
        }
       
       for(int index=n-1;index>=0;index--){
           for(int target=0;target<=t;target++){
               
                 bool include=0;
                 if(target-arr[index]>=0)
                   include=dp[index+1][target-arr[index]];
                   
                 bool exclude=dp[index+1][target];
        
                  dp[index][target]= include or exclude;
              }
       }
        
       return dp[0][t];
   }
   
      
   bool solveopt(vector<int>& arr,int n,int t){
        vector<int> curr(t+1,0);
        vector<int> next(t+1,0);
       curr[0]=1;
       next[0]=1;
       
       for(int index=n-1;index>=0;index--){
           for(int target=0;target<=t;target++){
               
                 bool include=0;
                 if(target-arr[index]>=0)
                   include=next[target-arr[index]];
                   
                 bool exclude=next[target];
        
                  curr[target]= include or exclude;
              }
              next=curr;
       }
        
       return next[t];
   }
   
   
    bool equalPartition(vector<int>& arr) {
     int n=arr.size();
     
     int total=0;
     for(int i=0;i<n;i++){
         total+=arr[i];
     }
     
     if(total&1){
         return 0;
     }
     
     int target=total/2;
    //  return solve(0,arr,n,target);
    // vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
    // return solvemem(0,arr,n,target,dp);
    
    // return solvetab(arr,n,target);
    
     return solveopt(arr,n,target);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends