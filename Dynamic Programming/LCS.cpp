class Solution {
public:
    int solve(int i,int j,string text1, string text2){
        int length=0;
        if(i==text1.size()||j==text2.size()){
            return 0;
        }

        //match
        if(text1[i]==text2[j]){
            length=1+solve(i+1,j+1,text1,text2);
        }else{
            length= max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));
        }
        return length;
    }

      int solvemem(int i,int j,string text1, string text2,vector<vector<int>> &dp){
        int length=0;
        if(i==text1.size()||j==text2.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //match
        if(text1[i]==text2[j]){
            length=1+solvemem(i+1,j+1,text1,text2,dp);
        }else{
            length= max(solvemem(i+1,j,text1,text2,dp),solvemem(i,j+1,text1,text2,dp));
        }
        return dp[i][j]=length;
    }

   int solvetab(string text1, string text2){
  
    int n=text1.size();
    int m=text2.size();
      vector<vector<int>> dp(n+1,vector<int> (text2.size()+1,0));
      for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
              int length=0;
           //match
        if(text1[i]==text2[j]){
            length=1+dp[i+1][j+1];
        }else{
            length= max(dp[i+1][j],dp[i][j+1]);
        }
         dp[i][j]=length;  
        }
      }
      return dp[0][0];
   }

   int solveopt(string text1, string text2){
  
    int n=text1.size();
    int m=text2.size();
     vector<int> curr(m+1,0);
     vector<int> next(m+1,0);
      for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
              int length=0;
           //match
        if(text1[i]==text2[j]){
            length=1+next[j+1];
        }else{
            length= max(next[j],curr[j+1]);
        }
         curr[j]=length;  
        }
        next=curr;
      }
      return next[0];
   }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        // return solve(0,0,text1,text2);
        // vector<vector<int>> dp(n,vector<int> (text2.size(),-1));
        // return solvemem(0,0,text1,text2,dp);

        // return solvetab(text1,text2);
         return solveopt(text1,text2);

    }
};