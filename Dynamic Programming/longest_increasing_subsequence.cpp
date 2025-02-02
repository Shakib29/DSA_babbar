//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    
    int solve(int n,vector<int>& arr,int curr,int prev){
        if(curr==n){
            return 0;
        }
        
        int include=0;
        if(prev==-1 || arr[curr]>arr[prev]) {
        include=1+solve(n,arr,curr+1,curr);
        }
        
        int exclude=0+solve(n,arr,curr+1,prev);
        return max(include,exclude);
        
    }
    
    int solvemem(int n,vector<int>& arr,int curr,int prev, vector<vector<int>> dp){
        if(curr==n){
            return 0;
        }
        
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        
        int include=0;
        if(prev==-1 || arr[curr]>arr[prev]) {
        include=1+solvemem(n,arr,curr+1,curr,dp);
        }
        
        int exclude=0+solvemem(n,arr,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);
        
    }
    
    int solvetab(int n,vector<int>& arr){
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
     for(int curr=n-1;curr>=0;curr--){
         for(int prev=curr-1;prev>=-1;prev--){
        int include=0;
        if(prev==-1 || arr[curr]>arr[prev]) {
        include=1+dp[curr+1][curr+1];
        }
        
        int exclude=0+dp[curr+1][prev+1];
        dp[curr][prev+1]= max(include,exclude);
         }
     }
     return dp[0][0];
        
    }
    
     
    int solveopt(int n,vector<int>& arr){
        vector<int> currROW(n+1,0);
         vector<int> next(n+1,0);
        
     for(int curr=n-1;curr>=0;curr--){
         for(int prev=curr-1;prev>=-1;prev--){
        int include=0;
        if(prev==-1 || arr[curr]>arr[prev]) {
        include=1+next[curr+1];
        }
        
        int exclude=0+next[prev+1];
        currROW[prev+1]= max(include,exclude);
         }
         next=currROW;
     }
     return next[0];;
        
    }
    
    int solveOPT(int n,vector<int>& arr){
        if(n==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(arr[0]);
        
        for(int i=1;i<n;i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
            }else{
            
            int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[index]=arr[i];
            }
        }
        return ans.size();
    }
    
    int longestSubsequence(vector<int>& arr) {
        int n=arr.size();
        // return solve(n,arr,0,-1);
        
        // vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        // return solvemem(n,arr,0,-1,dp);
        
    //   return solvetab(n,arr);
    // return solveopt(n,arr); 
   return solveOPT(n,arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.longestSubsequence(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends