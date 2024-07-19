#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
 
 
const int MOD = 1e9+7;
int main(){
	int n ,m;
	cin>>n>>m;

	vector<int>arr(n);
	for(int i =0;i<n;i++){
		cin>>arr[i];
	}
//we always ty to make the forst dimension range of a 2d vector smaller
	vector<vector<int>>dp(m+1,vector<int>(n,0));

//dp[k][idx]= number of suitable prefixes upto idx we can make if their last element is k

//transition = dp[k][idx]= dp[k-1][idx-1]+dp[k][idx-1]+dp[k+1][idx-1]
	//thus its divided into smaller subproblems :prefix upto (idx-1) with last element k-1,kand k+1


//base case :
//for the first element of the array we can fill it up by any v(1,m) if arr[0]=0;
// therefore all dp[v][0] =1;
//but if arr[0]!=0 and arr[0]=v so only dp[v][0]=1 and rest is 0. because only v can take its place.





	for(int i =1;i<=m;i++){
		if(arr[0]==0||arr[0]==i){
			dp[i][0]=1;
		}
	}

	for(int i=1;i<n;i++){
		//now for any i is arr[i]=0 we would calculate all dp[v][i] because any one from 1 to m could take its place.
		if(arr[i]==0){
			for(int j=1;j<=m;j++){
				int prev = 0;
				if(j-1>0)prev = dp[j-1][i-1];

				dp[j][i]= (dp[j][i]+prev)%MOD;
				int curr = dp[j][i-1];
				dp[j][i]= (dp[j][i]+curr)%MOD;
				int forward = 0;
				if(j+1<=m)forward = dp[j+1][i-1];
				dp[j][i]= (dp[j][i]+forward)%MOD;


			}

		}
		else{
	// but if arr[i]=k and arr[i]!=0  it could onbly be filled by k so we only calculate for that and neglect all values
			int k = arr[i];
				int prev = 0;
				if(k-1>0)prev = dp[k-1][i-1];

				dp[k][i]= (dp[k][i]+prev)%MOD;
				int curr = dp[k][i-1];
				dp[k][i]= (dp[k][i]+curr)%MOD;
				int forward = 0;
				if(k+1<=m)forward = dp[k+1][i-1];
				dp[k][i]= (dp[k][i]+forward)%MOD;			
		}
	}
	//final subproblem : return dp[k][n-1] if k!=0 
	//return sum of all dp[v][n-1] where v from 1 to m
	if(arr[n-1]==0){
		int res=0;
		for(int i =1;i<=m;i++){
			res = (res+dp[i][n-1])%MOD;
		}
		cout<<res<<endl;
	}
	else cout<<dp[arr[n-1]][n-1];
	

 
}
//time complexity = worst case when all elements are 0 , O(m*n)
//space optimisation
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
 
 
const int MOD = 1e9+7;
int main(){
	int n ,m;
	cin>>n>>m;

	vector<int>arr(n);
	for(int i =0;i<n;i++){
		cin>>arr[i];
	}

	vector<int>prevRow(m+1,0);






	for(int i =1;i<=m;i++){
		if(arr[0]==0||arr[0]==i){
			prevRow[i]=1;
		}
	}

	for(int i=1;i<n;i++){

		vector<int>curRow(m+1,0);
		if(arr[i]==0){
			for(int j=1;j<=m;j++){
				int prev = 0;
				if(j-1>0)prev = prevRow[j-1];

				curRow[j]= (curRow[j]+prev)%MOD;
				int curr = prevRow[j];
				curRow[j]= (curRow[j]+curr)%MOD;
				int forward = 0;
				if(j+1<=m)forward = prevRow[j+1];
				curRow[j]= (curRow[j]+forward)%MOD;


			}

		}
		else{

			int k = arr[i];
				int prev = 0;
				
				if(k-1>0)prev = prevRow[k-1];

				curRow[k]= (curRow[k]+prev)%MOD;
				int curr = prevRow[k];
				curRow[k]= (curRow[k]+curr)%MOD;
				int forward = 0;
				if(k+1<=m)forward = prevRow[k+1];
				curRow[k]= (curRow[k]+forward)%MOD;			
		}
		prevRow=curRow;
	}

	if(arr[n-1]==0){
		int res=0;
		for(int i =1;i<=m;i++){
			res = (res+prevRow[i])%MOD;
		}
		cout<<res<<endl;
	}
	else cout<<prevRow[arr[n-1]];
	

 
}
