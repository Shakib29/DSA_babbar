//1) recursion and memoization   ( top down approach)
#include <bits/stdc++.h>
using namespace std;


int fib(int n,vector<int> &dp){
  if(n<=1){
          return n;
  }
  if(dp[n]!=-1){
   return dp[n];
  }
 dp[n]= fib(n-1,dp)+fib(n-2,dp);
 return dp[n];
}
int main() {

  int n;
  cin >> n;
  vector<int> dp(n+1);
  for(int i=0;i<=n;i++){
          dp[i]=-1;
  }
 cout<<fib(n,dp);
 return 0;
}



//2) tabulation       ( bottom up approach)

#include <bits/stdc++.h>
using namespace std;


int fib(int n,vector<int> &dp){
 dp[0]=0;
 dp[1]=1;
 for(int i=2;i<=n;i++){
         dp[i]=dp[i-1]+dp[i-2];
 }
 return dp[n];
}
int main() {

  int n;
  cin >> n;
  vector<int> dp(n+1);
  for(int i=0;i<=n;i++){
          dp[i]=-1;
  }
 cout<<fib(n,dp);
 return 0;
}


//3) space optimiztion

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Handling base cases
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    } else if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Variables to store previous two Fibonacci numbers
    int n1 = 0;
    int n2 = 1;
    int curr;

    // Calculating Fibonacci sequence
    for (int i = 2; i <= n; i++) {
        curr = n1 + n2;
        n1 = n2;
        n2 = curr;
    }

    // Output the nth Fibonacci number
    cout << n2 << endl;
    return 0;
}
