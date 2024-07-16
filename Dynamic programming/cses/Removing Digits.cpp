#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
 
 
const int MOD = 1e9+7;
int main(){
	int n ;
	cin>>n;

	vector<int>dp(n+1,0);//dp[0]=0 base case

	for(int i = 1;i<=n;i++){
		int x = i;
		int mini = 1e7;


		while(x>0){
			int y = x%10;
			if(y!=0){
				mini = min(mini,dp[i-y]);
				

			}
			x=x/10;
		}

		dp[i]=1+mini;
	}
	cout<<dp[n]<<endl;

}

//Space optimisation : as we need only previous 9 states 
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
 
 
const int MOD = 1e9+7;
int main(){
	int n ;
	cin>>n;

	vector<int>dp(1,0);//dp[0]=0 base case

	//dp[i]= min number of steps to make this 0

	for(int i = 1;i<=n;i++){
		int x = i;
		int mini = 1e7;

		//transition dp[i]= 1+ min(dp[i-k]) where k are all the digits in i

		//space optimization: as digits of a number can only range from 0-9;
		//we need at max previous 9 states not any more
		// dp[i-K]==>dp[dp.size()-k] : as we just want kth previous state
		while(x>0){
			int y = x%10;
			if(y!=0){
				mini = min(mini,dp[dp.size()-y]);
				

			}
			x=x/10;
		}

		dp.push_back(1+mini);
		if(dp.size()>9)dp.erase(dp.begin());
	}
	cout<<dp.back()<<endl;

 

 
 
}
