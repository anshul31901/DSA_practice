https://cses.fi/problemset/task/1131
#include <bits/stdc++.h>
using namespace std;
#define mod 100000007
#define ll long long int
#define vi vector<int>
#define pb push_back
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
#define ff first
#define ss second





vvi adj(200001);
int vis[200001];
int maxdist= INT_MIN;
int farnode = -1;

void dfs(int v,int dist){
    vis[v]=dist;
    if(dist>maxdist){
        farnode=v;
        maxdist=dist;
    }
    for(auto child:adj[v]){
        if(vis[child]==-1){
            dfs(child,dist+1);
        }
    }
}


int main() {
  memset(vis,-1,sizeof(vis));
  int n,a,b;
  cin>>n;
  for(int i=0;i<n-1;i++){
    cin>>a>>b,adj[a].pb(b),adj[b].pb(a);
  }
  dfs(1,0);
  memset(vis,-1,sizeof(vis));
  dfs(farnode,0);
  cout<<maxdist<<endl;

 


}


