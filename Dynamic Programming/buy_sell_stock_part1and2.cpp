class Solution {
public:

   int solve(int index,int buy,vector<int>& prices){
    if(index==prices.size()){
        return 0;
    }
    int profit=0;
    if(buy){
    int buykaro= -prices[index]+solve(index+1,0,prices);
    int skipkaro= 0+solve(index+1,1,prices);
    profit=max(buykaro,skipkaro);
    }else{
        int sellkaro= +prices[index]+solve(index+1,1,prices);
    int skipkaro= 0+solve(index+1,0,prices);
    profit=max(sellkaro,skipkaro);
    }
   return profit;
   }

   int solvemem(int index,int buy,vector<int>& prices, vector<vector<int>> &dp){
    if(index==prices.size()){
        return 0;
    }

    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }

    int profit=0;
    if(buy){
    int buykaro= -prices[index]+solvemem(index+1,0,prices,dp);
    int skipkaro= 0+solvemem(index+1,1,prices,dp);
    profit=max(buykaro,skipkaro);
    }else{
        int sellkaro= +prices[index]+solvemem(index+1,1,prices,dp);
    int skipkaro= 0+solvemem(index+1,0,prices,dp);
    profit=max(sellkaro,skipkaro);
    }
   return dp[index][buy]=profit;
   }
 
  int solvetab(vector<int>& prices){
    int n=prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2,0));

    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
    if(buy){
    int buykaro= -prices[index]+dp[index+1][0];
    int skipkaro= 0+dp[index+1][1];
    profit=max(buykaro,skipkaro);
    }else{
        int sellkaro= +prices[index]+dp[index+1][1];
    int skipkaro= 0+dp[index+1][0];
    profit=max(sellkaro,skipkaro);
    }
    dp[index][buy]=profit;
        }
    }
    return dp[0][1];
  }

   int solveopt(vector<int>& prices){
    int n=prices.size();
    vector<int> curr(2,0);
    vector<int> next(2,0);
    for(int index=n-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
    if(buy){
    int buykaro= -prices[index]+next[0];
    int skipkaro= 0+next[1];
    profit=max(buykaro,skipkaro);
    }else{
        int sellkaro= +prices[index]+next[1];
    int skipkaro= 0+next[0];
    profit=max(sellkaro,skipkaro);
    }
    curr[buy]=profit;
        }
        next=curr;
    }
    return next[1];
  }


   int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // int mini = prices[0]; // Minimum price so far
    // int profit = 0;       // Maximum profit so far
    // for (int i = 1; i < n; i++) {
    //     int diff = prices[i] - mini; // Calculate potential profit
    //     profit = max(profit, diff);  // Update the maximum profit
    //     mini = min(mini, prices[i]); // Update the minimum price
    // }
    // return profit;


    // return solve(0,1,prices);

    // vector<vector<int>> dp(n+1, vector<int> (2,-1));
    // return solvemem(0,1,prices,dp);

    // return solvetab(prices);

    return solveopt(prices);
}
};