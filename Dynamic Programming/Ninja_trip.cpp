 int solve(int n, vector<int> &days, vector<int> &cost,int index){
     //base case
     if(index>=n){
        return 0;
     }
      //for 1 day pass
     int option1=cost[0]+solve(n,days,cost,index+1);

     //for 7days pass
     int i;
     for( i=index ; i<n && days[i]<days[index]+7; i++);

     int option2=cost[1]+solve(n,days,cost,i);

     //for 30days pass
          for( i=index;i<n&& days[i]<days[index]+30;i++);
     int option3=cost[2]+solve(n,days,cost,i);

     return min(option1, min(option2, option3));
 }


 int solvemem(int n, vector<int> &days, vector<int> &cost,int index,vector<int> &dp){
     //base case
     if(index>=n){
        return 0;
     }

     if(dp[index]!=-1){
         return dp[index];
     }
      //for 1 day pass
     int option1=cost[0]+solve(n,days,cost,index+1);

     //for 7days pass
     int i;
     for( i=index ; i<n && days[i]<days[index]+7; i++);

     int option2=cost[1]+solve(n,days,cost,i);

     //for 30days pass
          for( i=index;i<n&& days[i]<days[index]+30;i++);
     int option3=cost[2]+solve(n,days,cost,i);

     dp[index]=min(option1, min(option2, option3));
   return dp[index];
 }


 int solvetab(int n, vector<int> &days, vector<int> &cost){
     vector<int> dp(n+1,INT_MAX);
    dp[n]=0;

    for(int k=n-1;k>=0;k--){
        //for 1 day pass
     int option1=cost[0]+dp[k+1];

     //for 7days pass
     int i;
     for( i=k ; i<n && days[i]<days[k]+7; i++);

     int option2=cost[1]+dp[i];

     //for 30days pass
          for( i=k;i<n&& days[i]<days[k]+30;i++);
     int option3=cost[2]+dp[i];

     dp[k]= min(option1, min(option2, option3));
 
    }

     return dp[0];
 }



 int solveopt(int n, vector<int> &days, vector<int> &cost){
    int ans=0;
    queue<pair<int,int>> months;
    queue<pair<int,int>> weeks;

        for(int day:days){
     
     //step1 remove expired days
     while(!months.empty() && months.front().first + 30 <= day){
       months.pop();
     }
       while(!weeks.empty() && weeks.front().first + 7 <= day){
       weeks.pop();
     }

     //step2 add cost for current day

     weeks.push(make_pair(day,ans+cost[1]));
     months.push(make_pair(day,ans+cost[2]));

     //step 3 ans update
     ans=min(ans+cost[0],min(weeks.front().second,months.front().second));



        }
   return ans;
 }

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // return solve(n,days,cost,0);

    // vector<int> dp(n+1,-1);
    // return solvemem(n,days,cost,0,dp);

//    return solvetab(n,days, cost);

//optimized
  return solveopt(n,days,cost);
}