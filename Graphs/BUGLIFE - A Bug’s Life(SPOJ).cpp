#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

const int MOD = 1e9+7;

vector<int> adj[2001];
vector<int>vis(2001,-1);


bool dfs(int node,int c){
	vis[node]=c;

	for(auto child:adj[node]){
		//if unvisited check if we can colour child with opp color
		if(vis[child]==-1){
			if(dfs(child,1-c)==0){
				return false;
			}
		}
		else if(vis[child]==c)return false;
	}
	return true;
}

int main(){
	int t;
	cin>>t;

	for(int tc = 1;tc<=t;tc++){
		int n,m,a,b;
		cin>>n>>m;


		for(int i =1;i<=n;i++)adj[i].clear(),vis[i]=-1;

		while(m--){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool flag = true;
		for(int i =1;i<=n;i++){
			if(vis[i]==-1){
				if(dfs(i,1)==false){
					flag = false;
					break;
				}

			}
		}

		cout<<"Scenario #"<<tc<<":"<<endl;

		if(flag)cout<<"No suspicious bugs found!"<<endl;
		else cout<<"Suspicious bugs found!"<<endl;


	}
}



