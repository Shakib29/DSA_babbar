class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
     
         unordered_map<int,int> dp;
         int ans=0;

         for(int i=0;i<arr.size();i++){
            int temp=arr[i]-difference;
            int tempans=0;

            //check if answeer already existes or not in dp
            if(dp.count(temp)){
                tempans=dp[temp];      //dp[temp] matalb count hua 
            }
          //current answer update
            dp[arr[i]]=1+tempans;

            //ans update
            ans=max(ans,dp[arr[i]]);


         }
         return ans;
    }
};