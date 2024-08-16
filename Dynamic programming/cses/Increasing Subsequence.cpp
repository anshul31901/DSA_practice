

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int MOD = 1e9+7;




int main(){

	int n ;
	cin>>n;
	vector<int>arr(n+1);

	for(int i =1;i<=n;i++){
		cin>>arr[i];
	}
	vector<int>dp(n+1,1);
	dp[0]=0;


	//dp[i] = for every j from i to i-1 if arr[j]<arr[i] dp[i] = max(dp[i],1+dp[j])

	int maxi = 1;
	vector<int>lis;
	lis.push_back(arr[1]);
	for(int i =2;i<=n;i++){
		if(arr[i]>lis.back()){
			lis.push_back(arr[i]);
		}
		else{
			auto idx = lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
			swap(lis[idx],arr[i]);
		}
	}
	cout<<lis.size()<<endl;
	

	
 
}
