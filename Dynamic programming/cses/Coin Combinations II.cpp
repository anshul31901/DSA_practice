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

//space optimised solution
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

	// vector<vector<int>>dp(n+1,vector<int>(x+1));//O(n*x)
	for(int i =0;i<n;i++){
		cin>>coins[i];
	}

 //dp[i][sum]= dp[i+1][sum]//next row +dp[i][sum-coins[i]];
//depends upon next row of states and current row

	vector<int>nextState(x+1,0);//dp[n][sum]:no coins available
	nextState[0]=1;
	for(int i = n-1;i>=0;i--){ 
		vector<int>currentState(x+1,0);//this row
		currentState[0]=1;
		for(int sum =1;sum<=x;sum++){
			int pick =0;
			if(sum-coins[i]>=0){
				
					pick= currentState[sum-coins[i]];
						
			}
			int skip = nextState[sum];
 
			currentState[sum]= (pick+skip)%MOD;
			//prevState[sum]= dp[i+1][sum]
			//curState[sum-coins[i]]= dp[i][sum-coins[i]]
		}
		nextState=currentState;
	}
	cout<< nextState[x]<<endl;
 
 
 
 
 
 
 
 
}
