#include <bits/stdc++.h> 

int solve(vector<int> weight, vector<int> value, int index, int capacity){
	if(index==0){
		if(weight[index]<=capacity){
			return value[index];
		}else{
			return 0;
		}
	}
    
	int include = 0;
	if(weight[index]<=capacity){
		include=value[index]+solve(weight,value,index-1,capacity-weight[index]);
	}
	int exclude = 0;
	exclude=solve(weight,value,index-1,capacity);
	
	int ans=max(include,exclude);
	return ans;
} 


int solvemem(vector<int> weight, vector<int> value, int index, int capacity,vector<vector<int>> &dp){
	if(index==0){
		if(weight[index]<=capacity){
			return value[index];
		}else{
			return 0;
		}
	}


	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}
    
	int include = 0;
	if(weight[index]<=capacity){
		include=value[index]+solvemem(weight,value,index-1,capacity-weight[index],dp);
	}
	int exclude = 0;
	exclude=solvemem(weight,value,index-1,capacity,dp);
	
	dp[index][capacity]=max(include,exclude);
	return dp[index][capacity];
} 

int solvetab(vector<int> weight, vector<int> value, int n, int capacity){
	//1st creation of 2D array
	vector<vector<int>> dp(n,vector<int>(capacity+1,0));
	

	for(int w=weight[0];w<=capacity;w++){
		if(weight[0]<=capacity){
			dp[0][w]=value[0];
		}else{
			dp[0][w]=0; 
		}
	}
  
	for(int index=1;index<n;index++){
		for(int w=0;w<=capacity;w++){
			int include = 0;
	if(weight[index]<=w){
		include=value[index]+dp[index-1][w-weight[index]];
	}
	int exclude = 0;
	exclude=dp[index-1][w];
	
	dp[index][w]=max(include,exclude);

		}
	}
	return dp[n-1][capacity];
}


int solveopt(vector<int> weight, vector<int> value, int n, int capacity){
	vector<int> prev(capacity+1);
	vector<int> curr(capacity+1);
	// analyzing the base case
	for(int w=weight[0];w<=capacity;w++){
		if(weight[0]<=capacity){
			prev[w]=value[0];
		}else{
		  prev[w]=0; 
		}
	}
  //take care of remaining recursive calls
	for(int index=1;index<n;index++){
		for(int w=0;w<=capacity;w++){
			int include = 0;
	if(weight[index]<=w){
		include=value[index]+prev[w-weight[index]];
	}
	int exclude = 0;
	exclude=prev[w];
	
	curr[w]=max(include,exclude);

		}
	prev=curr;
	}
	return prev[capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// return solve(weight , value ,n-1 , maxWeight);

	//why 2D array ,because in recursive call ,2 arguments are changing
	// vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	// return solvemem(weight,value,n-1,maxWeight,dp);

	// return solvetab(weight , value ,n , maxWeight);
	return solveopt(weight , value ,n , maxWeight);
}