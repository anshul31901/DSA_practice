

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int MOD = 1e9+7;


int main(){

	//maximum sum can be n*1000 if all coins are of 1000 denominations

	int n ;
	cin>>n;
	int sum = (n*(n+1))/2;
	if(sum%2){
		cout<<0<<endl;
		return 0;
	}
	int target = sum/2;

	vector<vector<int>>dp(n+1,vector<int>(target+1,0));

	dp[0][0]=1;

	//dp[i][j]= number of ways to make sum j with first i numbers;



	for(int i =1;i<=n;i++){
		for(int j =1;j<=target;j++){

			//number of ways to make j with first i-1 numbers
			int skip = dp[i-1][j];


			int take=0;
			//include i
			//number of ways to make j - i with first i-1 numbers
			if(j-i>=0){
				take = dp[i-1][j-i];

			}

			dp[i][j]= (take + skip)%MOD;
		}

	}
	cout<<dp[n][target]<<endl;
	






 
}
//time complexity : O(n^3)
//space optimization


#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int MOD = 1e9+7;


int main(){

	//maximum sum can be n*1000 if all coins are of 1000 denominations

	int n ;
	cin>>n;
	int sum = (n*(n+1))/2;
	if(sum%2){
		cout<<0<<endl;
		return 0;
	}
	int target = sum/2;

	vector<int>prev(target+1,0);


	prev [0]=1;

	//dp[i][j]= number of ways to make sum j with first i numbers;


	vector<int>cur(target+1,0);
	for(int i =1;i<=n;i++){

		for(int j =1;j<=target;j++){

			//number of ways to make j with first i-1 numbers
			int skip = prev[j];


			int take=0;
			//include i
			//number of ways to make j - i with first i-1 numbers
			if(j-i>=0){
				take = prev[j-i];

			}

			cur[j]= (take + skip)%MOD;
		}
		prev=cur;

	}
	cout<<prev[target]<<endl;
	






 
}

