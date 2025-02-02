class Solution {
public:

   int solve(vector<int>& v,int i,int j){
    if(i+1==j){
        return 0;
        }
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,v[i]*v[j]*v[k],solve(v,i,k),solve(v,k,j));
    }
    return ans;

   }

    int solvemem(vector<int>& v,int i,int j, vector<int> dp){
    if(i+1==j){
        return 0;
        }
     if(dp[i][j]!=-1){
        return dp[i][j];
     }

    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        dp[i][j]=min(ans,v[i]*v[j]*v[k],solve(v,i,k),solve(v,k,j));
    }
    return dp[i][j];

   }


   int solvetab(vector<int>& values){
        int n=values.size();
     vector<int> dp(n+1,0);
     for(int i=n-1;i>=0;i--){
        for(int j=i+2;j<n;j++){
             int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        dp[i][j]=min(ans,v[i]*v[j]*v[k],solve(v,i,k),solve(v,k,j));
    }
    dp[i][j]=ans;
        }
     }
return dp[0][n-1];
   }

    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        // solve(values,0,n-1);
    //     vector<int> dp(n+1,-1);
    //    return  solvemem(values,0,n-1,dp);
    return solvetab(values);


    }
};