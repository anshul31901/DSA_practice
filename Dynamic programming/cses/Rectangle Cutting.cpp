

#include<bits/stdc++.h>
using namespace std;
#define ll long long 



// int solve(int l,int b){
// 	if(l==b)return dp[l][b]=0;

// 	if(dp[l][b]!=-1)return dp[l][b];

// 	int ans = INT_MAX;

// 	for(int i=1;i<=l-1;i++){
// 		ans = min(ans,solve(i,b)+solve(l-i,b));
// 	}
// 	for(int i=1;i<=b-1;i++){
// 		ans = min(ans,solve(l,i)+solve(l,b-i));
// 	}
// 	return dp[l][b]=1+ans;
// }


int main(){
	int a,b;
	cin>>a>>b;


    vector<vector<int>>dp(a+1,vector<int>(b+1,1e9));

    //dp[l][k]=min cuts to convert recatngle of length l and breadth k to all squares

    //make all possible vectical cuts and make all possible horizontal cuts
    for(int l =1;l<=a;l++){
    	for(int k =1;k<=b;k++){
    		if(l==k)dp[l][k]=0;
    		else{
    			for(int i = 1;i<=l-1;i++ ){
    				dp[l][k]= min(dp[l][k],1+dp[i][k]+dp[l-i][k]);
    			}
    			for(int j=1;j<=k-1;j++){
    				dp[l][k]= min(dp[l][k],1+dp[l][j]+dp[l][k-j]);
    			}
    		}
    	}
    }
    cout<<dp[a][b]<<endl;

    //Time complexity O(a*b)(a+b)
    // no. of states * avg computation time for each state


 
}
//we need all prev l-1 states and b-1 states so space optimisation is not further possible
