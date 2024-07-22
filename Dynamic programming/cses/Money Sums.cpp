
//using sets complexity : (n^2)logn
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
 	int n;
 	cin>>n;

 	int arr[n];//stores all coin denominations

 	for(int i =0;i<n;i++){
 		cin>>arr[i];
 	}
 	sort(arr,arr+n);

 	set<int>sums;//stores all the possible sums that have occures;

 	sums.insert(arr[0]);

 	for(int i =1;i<n;i++){

 		int coin = arr[i];
 		set<int>temp;
 		if(sums.find(coin)==sums.end()){
 			temp.insert(coin);
 		}
 		

 		for(auto x:sums){
 			temp.insert(coin+x);
 		}
 		for(auto x:temp){
 			sums.insert(x);
 		}


 	}

 	cout<<sums.size()<<endl;
 	for(auto i:sums){
 		cout<<i<<" ";
 	}
 	cout<<endl;
 
}
// using dynamic programming 0-1 knapsack


#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<vector<bool>>dp(100+1,vector<bool>(1e5+1,false));


int main(){

	//maximum sum can be n*1000 if all coins are of 1000 denominations

	int n ;
	cin>>n;

	int arr[n];
	for(int i =0;i<n;i++)cin>>arr[i];

	int max_sum = 1000*n;

	//dp[i][j]: if i can make sum j with first i coins

	dp[0][0]=true;
	for(int i =1;i<=n;i++){
		for(int j =0;j<=max_sum;j++){
			dp[i][j]= dp[i-1][j];//if i can make sum j with prev i-1 coins

			//if i take this coin what remaining sum will be left
			int left = j-arr[i-1];
			if(left>=0&&dp[i-1][left])dp[i][j]=true;


		}
	}
	vector<int>possible;
//what are the possible sums i can make with these n coins
	for(int j=1;j<=max_sum;j++){
		if(dp[n][j])possible.push_back(j);
	}
	cout<<possible.size()<<endl;
	for(auto sum:possible)cout<<sum<<" ";

	cout<<endl;


 
}
//time complexity = O(n^2.1e3);
