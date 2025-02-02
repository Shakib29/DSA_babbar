#include <bits/stdc++.h> 
#define MOD 1000000007
int solve(int nStairs,int i,vector<int> &dp){
    //base case
    if(i==nStairs){
        return 1;
    }
    if(i>nStairs){
        return 0;         //outof bound case
    }
    if(dp[i]!=-1){
        return dp[i];
    }

 dp[i]=((solve(nStairs,i+1,dp)+solve(nStairs,i+2,dp))% MOD);
 return dp[i];
}
int countDistinctWays(int nStairs) {
   vector<int> dp(nStairs+1,-1);
   return solve(nStairs,0,dp);
   

}