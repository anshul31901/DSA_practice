#include<bits/stdc++.h>
using namespace std;

#define ll long long int

struct project{
	int st = 0;
	int ed = 0;
	int reward = 0;
};
static bool comp(project &a, project &b){
	return a.ed<b.ed;
}

//dp[l][r]= max (s1-s2 )when the currect player starts
//relation:  dp[l][r] = max (v[l]+dp[l+1][r](by other player),v[r]+dp[l][r-1](by other player)  = max(v[l]-dp[l+1][r],v[r]-dp[l][r-1])
// v[l]-(s2-s1)= v[l]+s1-s2
//l moves from n-1 to 0 and r moves from 0 to n-1

// base case when l==r dp[l][r]= v[l]

int main(){
	ll n;
	cin>>n;

	vector<ll>v(n);
	ll sum=0;
	for(int i =0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	vector<vector<ll>>dp(n,vector<ll>(n,0));

	for(int l =n-1;l>=0;l--){
		for(int r=l;r<n;r++){
			if(l==r){
				dp[l][r]= v[l];
			}
			else dp[l][r]= max(v[l]-dp[l+1][r],v[r]-dp[l][r-1]);

		}

	}
	//s1 -s2 = dp[0][n-1]
	// s1-(s-s1) = 2s1-s=dp[0][n-1]
	cout<<(dp[0][n-1]+sum)/2<<endl;

}
