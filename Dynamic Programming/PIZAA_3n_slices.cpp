#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    // 1. Recursive without DP
    int solveRecursive(int index, int endIndex, vector<int>& slices, int n) {
        if (n == 0 || index > endIndex) {
            return 0;
        }
        int take = slices[index] + solveRecursive(index + 2, endIndex, slices, n - 1);
        int notTake = solveRecursive(index + 1, endIndex, slices, n);
        return max(take, notTake);
    }

    // 2. Recursive with Memoization
    int solveMemo(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {
        if (n == 0 || index > endIndex) {
            return 0;
        }
        if (dp[index][n] != -1) {
            return dp[index][n];
        }
        int take = slices[index] + solveMemo(index + 2, endIndex, slices, n - 1, dp);
        int notTake = solveMemo(index + 1, endIndex, slices, n, dp);
        return dp[index][n] = max(take, notTake);
    }

    // 3. Tabulation
    int solveTabulation(vector<int>& slices, int start, int end, int n) {
        int len = end - start + 1;
        vector<vector<int>> dp(len + 1, vector<int>(n + 1, 0));
        for (int index = len - 1; index >= 0; --index) {
            for (int count = 1; count <= n; ++count) {
                int take = slices[start + index] + (index + 2 <= len - 1 ? dp[index + 2][count - 1] : 0);
                int notTake = dp[index + 1][count];
                dp[index][count] = max(take, notTake);
            }
        }
        return dp[0][n];
    }

    // 4. Space-Optimized Tabulation
    int solveSpaceOptimized(vector<int>& slices, int start, int end, int n) {
        int len = end - start + 1;
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int index = len - 1; index >= 0; --index) {
            vector<int> temp(n + 1, 0);
            for (int count = 1; count <= n; ++count) {
                int take = slices[start + index] + (index + 2 <= len - 1 ? prev[count - 1] : 0);
                int notTake = curr[count];
                temp[count] = max(take, notTake);
            }
            prev = curr;
            curr = temp;
        }
        return curr[n];
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;

        // Recursive without DP
        int case1Recursive = solveRecursive(0, slices.size() - 2, slices, n);
        int case2Recursive = solveRecursive(1, slices.size() - 1, slices, n);

        // Recursive with Memoization
        vector<vector<int>> dp1(slices.size(), vector<int>(n + 1, -1));
        vector<vector<int>> dp2(slices.size(), vector<int>(n + 1, -1));
        int case1Memo = solveMemo(0, slices.size() - 2, slices, n, dp1);
        int case2Memo = solveMemo(1, slices.size() - 1, slices, n, dp2);

        // Tabulation
        int case1Tab = solveTabulation(slices, 0, slices.size() - 2, n);
        int case2Tab = solveTabulation(slices, 1, slices.size() - 1, n);

        // Space-Optimized Tabulation
        int case1SpaceOpt = solveSpaceOptimized(slices, 0, slices.size() - 2, n);
        int case2SpaceOpt = solveSpaceOptimized(slices, 1, slices.size() - 1, n);

        // Output the results
        cout << "Recursive Without DP: " << max(case1Recursive, case2Recursive) << endl;
        cout << "Recursive With Memoization: " << max(case1Memo, case2Memo) << endl;
        cout << "Tabulation: " << max(case1Tab, case2Tab) << endl;
        cout << "Space-Optimized Tabulation: " << max(case1SpaceOpt, case2SpaceOpt) << endl;

        // Return any one as the final result
        return max(case1SpaceOpt, case2SpaceOpt);
    }
};


