//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
  int solve(int index,int diff,vector<int> &arr){
      if(index<0){
          return 0;
      }
      int ans=0;
      for(int j=index-1;j>=0;j--){
          if(arr[j]-arr[index]==diff){
              ans=max(ans,1+solve(j,diff,arr));
          }
      }
      return ans;
  }
  
  int solvemem(int index,int diff,vector<int> &arr,unordered_map<int,int> dp[]){
      if(index<0){
          return 0;
      }
      
      if(dp[index].count(diff)){
          return dp[index][diff];
      }
      int ans=0;
      
      for(int j=index-1;j>=0;j--){
          if(arr[j]-arr[index]==diff){
              ans=max(ans,1+solvemem(j,diff,arr,dp));
          }
      }
      return dp[index][diff]=ans;
  }
  
    int lengthOfLongestAP(vector<int>& arr) {
      int n=arr.size();
    //   if(n<=2){
    //       return n;
    //   }
    //   int ans=0;
      
    //   unordered_map<int,int> dp[n+1];
      
    //   for(int i=0;i<n;i++){
    //       for(int j=i+1;j<n;j++){
    //           ans=max(ans,2+solvemem(i,arr[i]-arr[j],arr,dp)); 
    //       }
    //   }
    //   return ans;
    
    
    //tabulation method
    
    if(n<=2){
        return n;
    }
    int ans=0;
    unordered_map<int,int> dp[n+1];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int diff=arr[i]-arr[j];
            int cnt=1;
            
            //check if answer already present
            if(dp[j].count(diff)){
                cnt=dp[j][diff];
            }
            
            dp[i][diff]=1+cnt;
            ans=max(ans,dp[i][diff]);
        }
    }
    return ans;
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
        auto ans = ob.lengthOfLongestAP(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends