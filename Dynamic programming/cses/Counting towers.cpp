#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
 vector<vector<int>>dp(1e6+1,vector<int>(2,0));

 //complexity = O(t*n)
const int MOD = 1e9+7;
int main(){
	int t ;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		//base cases : if from n-1th row a horizontal block is extending only 1 way to fill upto nth row that is to stop it


		dp[n][0]=1;
		dp[n][1]=1;//if 2 vertical blocks are extending from n-1th row only 1 way to stop them

		for(int i = n-1;i>=1;i--){
			//if from n-1th row a horizontal block is extending we have 3 cases 
			//eithrt to keep it extending or block it and start another horizontal block both dp[i+1][0]
			//or to stop and start a vertical block dp[i+1][1]
			dp[i][0]= (1ll*2*dp[i+1][0]+dp[i+1][1])%MOD;
			dp[i][1]= (1ll*4*dp[i+1][1]+dp[i+1][0])%MOD;

		}
		//final subproblem whatever will start will start from 0th row
//we have 2 options either start horizontal block or 2 vertical from 0th row
		//but before zero none can start so 
		cout<<(dp[1][0]+dp[1][1])%MOD<<endl;
	}
	

 
}
