#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

const int MOD = 1e9+7;




vector<vector<int>>adj(1e5+1);
vector<int>vis(1e5+1,-1);//vis array stores dist from 1

//backtrack from destination to source
//trick is we traverse only one branch that lead us to the source
// condition dist[child]= dist[node]-1
//(the child that we are going to track back to should take us to parent in dist[[parent]-1 steps])
//after finding one such child we do not seek any more childs and just track back 
void dfs(int node,vector<int>&res){
	

	res.push_back(node);
	if(node==1)return;

	for(auto child:adj[node]){
		if(vis[child]==vis[node]-1){
			dfs(child,res);
			return;
		}

	}

}

int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int a ,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//with bfs first find shortest dist to all computers
	queue<int>q;
	q.push(1);
	vis[1]=1;



	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto child:adj[node]){
			if(vis[child]==-1){
				vis[child]= vis[node]+1;
				q.push(child);
			}
		}
	}

	//if n is not in this cc we cant reach it hence print impossible
	if(vis[n]==-1){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}


	else cout<<vis[n]<<endl;
	vector<int>res;

	//otherwise backtrack from destination to source
	dfs(n,res);
	reverse(res.begin(),res.end());

	for(int i =0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;


}



