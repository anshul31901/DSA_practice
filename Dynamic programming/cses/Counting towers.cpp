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
// time optimisation : instead of calculating for n t times seperately.. precompute all upto 1e6 values and just answer the queries
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
 vector<vector<int>>dp(1e6+1,vector<int>(2,0));

 //complexity = O(n)
 //space complexity : O(1e6*2)
const int MOD = 1e9+7;
int main(){
		dp[1e6][0]=1;
		dp[1e6][1]=1;

		for(int i = 1e6-1;i>=1;i--){

			dp[i][0]= (1ll*2*dp[i+1][0]+dp[i+1][1])%MOD;
			dp[i][1]= (1ll*4*dp[i+1][1]+dp[i+1][0])%MOD;

		}
	int t ;
	cin>>t;


	while(t--){
		int n ;
		cin>>n;
	//we need a n length block , we cans ee this as our base of the tower starts as (1e6-n)th row
	//so either horizontal block can start from the base or 2 vertical ones so summation of both these cases 
	// for our next roe is ans 


		cout<<(dp[1e6-(n-1)][0]+dp[1e6-(n-1)][1])%MOD<<endl;
	}
	

 
}

