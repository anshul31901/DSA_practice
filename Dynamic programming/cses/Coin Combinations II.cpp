#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
 
 
const int MOD = 1e9+7;
int main(){
 
 
	int n,x;
	cin>>n>>x;
	vector<int>coins(n);
	//initialising dp[i] with very high values initially
	//dp[i] = number of ways to generate i sum
	vector<vector<int>>dp(n+1,vector<int>(x+1));
	for(int i =0;i<n;i++){
		cin>>coins[i];
	}
 
 
	for(int i =0;i<n;i++){
 
		dp[i][0]=1;
	}
 
	for(int i = n-1;i>=0;i--){ 
		for(int sum =1;sum<=x;sum++){
			int pick =0;
			if(sum-coins[i]>=0){
				
					pick= dp[i][sum-coins[i]];
						
			}
			int skip = dp[i+1][sum];
 
			dp[i][sum]= (pick+skip)%MOD;
		}
	}
	cout<< dp[0][x]<<endl;
 
 
 
 
 
 
 
 
}
