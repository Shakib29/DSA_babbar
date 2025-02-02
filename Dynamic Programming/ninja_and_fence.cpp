#include <bits/stdc++.h>

#define MOD 1000000007

// This code in memoiszation
int soln(int n, int &k, vector<int> &dp) {
  if (n == 1)
    return k;
  if (n == 2)
    return (1LL * k * k) % MOD;

  if (dp[n] != -1)
    return dp[n];

  return dp[n] = (1LL * (k - 1) *
                  (soln(n - 1, k, dp) % MOD + soln(n - 2, k, dp) % MOD) % MOD) %
                 MOD;
}

// by tabulation
int tabulation(int n, int k) {
  vector<int> dp(n + 1, -1);

  dp[0] = 0;
  dp[1] = k;
  dp[2] = (1LL * k * k) % MOD;

  for (int i = 3; i <= n; i++) {
    dp[i] = ((1LL * (k - 1)) * ((dp[i - 1] + dp[i - 2]) % MOD)) % MOD;
  }

  return dp[n];
}

// space optimization
int soln(int n, int k) {
  vector<int> dp(3, -1);

  dp[0] = 0;
  dp[1] = k;
  dp[2] = (1LL * k * k) % MOD;

  for (int i = 3; i <= n; i++) {
    int temp = dp[2];
    dp[2] = ((1LL * (k - 1)) * ((dp[2] + dp[1]) % MOD)) % MOD;
    dp[1] = temp;
  }

  return dp[2];
}

int numberOfWays(int n, int k) {
  vector<int> dp(n + 1, -1);
  // return soln(n, k, dp) % MOD;
  // return tabulation(n, k);
  return soln(n, k);
}
