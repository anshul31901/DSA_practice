https://www.codechef.com/problems/FIRESC#

//we have to just count the connected components and multiply size of each connected component to each other.
//no. of ways of becoming leader is equal to product of their sizes // permutations and combinations
  
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


ll cc_size;
vvi adj(100001);
int vis[100001];

void dfs(int v){
    vis[v]=1;
    cc_size++;
    for(auto child:adj[v]){
        if(vis[child]==0)dfs(child);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        
        ll cc_ct=0;
        ll ways =1;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            vis[i]=0;
            adj[i].clear();
        }
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            adj[a].pb(b),adj[b].pb(a);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                
                cc_size=0;
                dfs(i),cc_ct++;
                ways=(ways*cc_size)%mod;

            }
        }
        cout<<cc_ct<<" "<<ways<<endl;
       


    }

}
