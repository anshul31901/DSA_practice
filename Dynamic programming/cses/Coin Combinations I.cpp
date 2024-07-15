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
	vector<int>dp(x+1,0);
	for(int i =0;i<n;i++){
		cin>>coins[i];
	}
	//base case
	dp[0]=1;//
 
	for(int i =1;i<=x;i++){
		for(auto &coin:coins){
			if(i-coin>=0){
				dp[i]=(dp[i]+dp[i-coin])%MOD;
			}
		}
 
	}
	cout<<dp[x]<<endl;
 
 
 
 
 
 
}
