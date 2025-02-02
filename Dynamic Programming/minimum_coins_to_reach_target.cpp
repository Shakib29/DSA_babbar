#include <bits/stdc++.h> 

int solverec(vector<int> &num, int x){
if(x==0){
    return 0;
}

if(x<0){
    return INT_MAX;
}
int mini=INT_MAX;
for(int i=0;i<num.size();i++){
   int ans=solverec(num, x-num[i]);
    if(ans!=INT_MAX){
        mini=min(mini,1+ans);
    }
}
return mini;
}

int solvemem(vector<int> &num, int x,vector<int> &dp){
if(x==0){
    return 0;
}

if(x<0){
    return INT_MAX;
}
if(dp[x]!=-1){
    return dp[x];
}
int mini=INT_MAX;
for(int i=0;i<num.size();i++){
   int ans=solverec(num, x-num[i]);
    if(ans!=INT_MAX){
        mini=min(mini,1+ans);
    }
}
dp[x]=mini;
return mini;
}


// Function to solve the problem using Tabulation (Bottom-Up DP)
int solveTab(vector<int> &num, int x) {
    // Step 1: Initialize DP Table
    vector<int> dp(x + 1, INT_MAX); // dp[i] stores the minimum elements needed to form sum 'i'
    dp[0] = 0; // Base case: To form sum 0, we need 0 elements

    // Step 2: Fill DP Table
    for (int i = 1; i <= x; i++) { // Solve for every target sum from 1 to x
        for (int j = 0; j < num.size(); j++) { // Check every number in 'num'
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    // Step 3: Return the Result
    if (dp[x] == INT_MAX) {
        return -1; // If target sum 'x' is not achievable
    }
    return dp[x]; // Minimum number of elements to form sum 'x'
}


int minimumElements(vector<int> &num, int x)
{
    // int ans=solverec(num,x);
    // if(ans==INT_MAX)
    // return -1;x

    // vector<int> dp(x+1,-1);
    // int ans=solvemem(num,x,dp);

    // if(ans==INT_MAX){
    //     return -1;
    // }else{
    //     return ans;
    // }

   solveTab(num,x);
}