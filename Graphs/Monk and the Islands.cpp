https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/?purpose=login&source=problem-page&update=google
//simple bfs just instead of making pair for counting distance of each node i have run another loop .Its a bit mathematical 
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
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



vvi adj(100001);
int vis[100001];

void dfs(int v){
    vis[v]=1;

    for(auto child:adj[v]){
        if(vis[child]==0)dfs(child);
    }
}
void solve(){
    
        int n,m,a,b;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            vis[i]=0;
            adj[i].clear();
        }
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            adj[a].pb(b),adj[b].pb(a);
        }
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int chalo=0;

        while(!q.empty()){
            int length = q.size();
            while(length--){
                int cur = q.front();
                if(cur==n){
                    cout<<chalo<<endl;
                    return;
                }
                q.pop();
                for(auto child:adj[cur]){
                    if(vis[child]==0)q.push(child),vis[child]=1;
                }
            }
            chalo++;
        }
        

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
