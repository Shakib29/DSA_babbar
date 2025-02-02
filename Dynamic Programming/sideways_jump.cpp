//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array




class Solution {
public:

     int solve(vector<int>& obstackles,int currlane,int currpos){
        int n=obstackles.size()-1;
        if(currpos==n){
            return 0;
        }
        if(obstackles[currpos+1]!=currlane){
           return  solve(obstackles,currlane,currpos+1);
        }
            //sideways jump
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
              if((currlane!=i)&&(obstackles[currpos]!=i)){
                ans=min(ans, 1 + solve(obstackles,i,currpos));
              }
             
            }
             return ans;
        
     }
     
     int solvemem(vector<int>& obstacles,int currlane,int currpos,vector<vector<int>>& dp){
          int n=obstacles.size()-1;
        if(currpos==n){
            return 0;
        }
        
        if(dp[currlane][currpos]!=-1){
            return dp[currlane][currpos];
        }
        
        if(currpos + 1 < obstacles.size() &&  obstacles[currpos+1]!=currlane){
            return dp[currlane][currpos]=   solvemem(obstacles,currlane,currpos+1,dp);
        }else{
            //sideways jump                                 
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
              if(currlane!=i&&obstacles[currpos]!=i){
                ans=min(ans, 1 + solvemem(obstacles,i,currpos,dp));
              }
             
             
            }
             dp[currlane][currpos]=ans;
             return dp[currlane][currpos];
        }
     }

    int solvetab(vector<int>& obstacles){
        int n=obstacles.size();
        vector<vector<int>> dp(4,vector<int> (obstacles.size(),INT_MAX));
        dp[0][n];
         dp[1][n];
          dp[2][n];
           dp[3][n];
           
           for(int currpos=n-1;currpos>=0;currpos--){
               for(int currlane=1;currlane<=3;currlane++){
                    
       
        
        if( obstacles[currpos+1]!=currlane){
            dp[currlane][currpos]=  dp[currlane][currpos+1];
        }else{
            //sideways jump                                 
           
            for(int i=1;i<=3;i++){
              if(currlane!=i&&obstacles[currpos]!=i){
                dp[currlane][currpos]=min(dp[currlane][currpos], 1 + dp[i][currpos+1]);
              }
             
             
            }
            
         
        }
               }
           }
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
    }
    
    
    int solveopt(vector<int>& obstacles){
        int n=obstacles.size();
        vector<int> curr(4,INT_MAX);
         vector<int> next(4,INT_MAX);
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;
           
           for(int currpos=n-1;currpos>=0;currpos--){
               for(int currlane=1;currlane<=3;currlane++){
                    
       
        
        if( obstacles[currpos+1]!=currlane){
            curr[currlane]=next[currlane];
        }else{
            //sideways jump                                 
           
            for(int i=1;i<=3;i++){
              if(currlane!=i&&obstacles[currpos]!=i){
                curr[currlane]=min(curr[currlane], 1 + next[i]);
              }
             
             
            }
            
         
        }
               }
               next=curr;
               
           }
        return min(next[2],min(1+next[1],1+next[3]));
    }
    
    int minJumps(vector<int>& obstacles) {
        // return solve(obstacles,2,0);
        
        // vector<vector<int>> dp(4,vector<int> (obstacles.size(),-1));
        // return solvemem(obstacles,2,0,dp);
        
        // return solvetab(obstacles);
        return  solveopt(obstacles);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends