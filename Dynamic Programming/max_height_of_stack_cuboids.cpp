class Solution {
public:
   
  bool check(vector<int> base,vector<int> newbox){
    if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]){
        return true;
    }else{
        return false;
    }
  }

   int solvetab(int n,vector<vector<int>>& arr){
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
     for(int curr=n-1;curr>=0;curr--){
         for(int prev=curr-1;prev>=-1;prev--){
        int include=0;
        if(prev==-1 || check(arr[curr],arr[prev]) ){
        include=arr[curr][2]+dp[curr+1][curr+1];
        }
        
        int exclude=0+dp[curr+1][prev+1];
        dp[curr][prev+1]= max(include,exclude);
         }
     }
     return dp[0][0];
        
    }


    int maxHeight(vector<vector<int>>& cuboids) {

    //sort all dimensions fro all the cuboids 
    for(auto &a: cuboids){
        sort(a.begin(),a.end());
    }

    //sort cuboids on basis of the lenght or width 
    sort(cuboids.begin(),cuboids.end());
     
    // use the longest increasing subsequence
    return solvetab(cuboids.size(),cuboids);
     



    }
};