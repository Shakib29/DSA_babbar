//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  long long solve(int faces, int dices, int target) {
      // Base cases
      if (target < 0) return 0;
      if (dices == 0 && target == 0) return 1; // Perfect match
      if (dices == 0 || target == 0) return 0; // No dice or no target
      
      long long ans = 0;
      for (int i = 1; i <= faces; i++) {
          ans += solve(faces, dices - 1, target - i);
      }
      return ans;
  }
  
  long long solvemem(int faces, int dices, int target, vector<vector<long long>>& dp) {
      // Base cases
      if (target < 0) return 0;
      if (dices == 0 && target == 0) return 1;
      if (dices == 0 || target == 0) return 0;
      
      if (dp[dices][target] != -1) {
          return dp[dices][target]; // Return if already computed
      }
      
      long long ans = 0;
      for (int i = 1; i <= faces; i++) {
          ans += solvemem(faces, dices - 1, target - i, dp);
      }
      dp[dices][target] = ans;
      return dp[dices][target];
  }
  
  long long solvetab(int f, int d, int t) {
      vector<vector<long long>> dp(d + 1, vector<long long>(t + 1, 0));
      dp[0][0] = 1;
      
      for (int dice = 1; dice <= d; dice++) {
          for (int target = 1; target <= t; target++) {
              long long ans = 0;
              for (int i = 1; i <= f; i++) {
                  if (target - i >= 0)
                      ans += dp[dice - 1][target - i];
              }
              dp[dice][target] = ans;
          }
      }
      return dp[d][t];
  }
  
  long long solveopt(int f, int d, int t) {
      vector<long long> prev(t + 1, 0);
      vector<long long> curr(t + 1, 0);
      prev[0] = 1;
      
      for (int dice = 1; dice <= d; dice++) {
          for (int target = 1; target <= t; target++) {
              long long ans = 0;
              for (int i = 1; i <= f; i++) {
                  if (target - i >= 0)
                      ans += prev[target - i];
              }
              curr[target] = ans;
          }
          prev = curr;
      }
      return curr[t];
  }
  
  long long noOfWays(int m, int n, int x) {
      if (x < 0 || n < 0 || m <= 0) {
          return 0; // No valid ways
      }
      
      // Uncomment the desired approach
      // return solve(m, n, x);
      
      // vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, -1));
      // return solvemem(m, n, x, dp);
      
      // return solvetab(m, n, x);
      return solveopt(m, n, x);
  }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ts;
        getline(cin, ts);
        stringstream ss(ts);
        int number;
        int f = 0;
        int m, n, x;
        while (ss >> number) {
            if (f == 0)
                m = number;
            else if (f == 1)
                n = number;
            else
                x = number;
            f++;
        }

        // cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(m, n, x) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends