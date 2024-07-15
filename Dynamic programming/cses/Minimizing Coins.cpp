#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
 
 
const int MOD = 1e9+7;
int main(){
 
 
	int n,x;
	cin>>n>>x;
	vector<int>coins(n);
	//initialising dp[i] with very high values initially
	//dp[i] = min number of coins used to generate sum i
	vector<int>dp(x+1,1e9);
	for(int i =0;i<n;i++){
		cin>>coins[i];
	}
	//base case
	dp[0]=0;
 
	for(int i =1;i<=x;i++){
		for(auto &coin:coins){
			if(i-coin>=0&&dp[i-coin]<1e9){
				dp[i]=min(dp[i],1+dp[i-coin]);
			}
		}
 
	}
	int res =  dp[x]<1e9?dp[x]:-1;
	cout<<res<<endl;
 
 
 
 
 
