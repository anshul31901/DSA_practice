#include<bits/stdc++.h>
using namespace std;




const int MOD = 1e9+7;
int main(){
	int n;
	cin>>n;
	vector<int>dp(n+1);

	dp[0]=1;//base case
	//dp[n]: number of ways to get a sum n;

	for(int i =1;i<=n;i++){
		for(int j =1;j<=6;j++){
			if(i>=j){
				dp[i] = (dp[i]+dp[i-j])%MOD;
			}
		}
	}
	cout<<dp[n]<<endl;



}

//space optimised as we only need at most 6 prevsious dp states
#include<bits/stdc++.h>
using namespace std;
#define ll long long 



const int MOD = 1e9+7;
int main(){


	int n;
	cin>>n;
	//base case : when to make zero we need only one combination to not throw dice
	vector<int>prev(1,1);//only contains dp[0]
	for(int i =1;i<=n;i++){
		int current = 0;
		for(auto &e:prev){
			current = (current+e)%MOD;
		}
		prev.push_back(current);

		//as i need only 6 prev values everytime
		if(prev.size()>6){prev.erase(prev.begin());}
		
	}
	cout<<prev.back()<<endl;








}
