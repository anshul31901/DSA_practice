https://www.spoj.com/problems/TOPOSORT/
//just toposorting using priority queue
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
#define rep(i,a,b) for(int i=a;i<=b;i++)


vvi adj(100001);
int vis[100001];

int main(){
    int n,m,a,b;
    cin>>n>>m;
    vi ans;
    vi in(100001,0);
    rep(i,1,m){
        cin>>a>>b;
        adj[a].pb(b),in[b]++;
    }
     priority_queue<int,vector<int>,greater<int>>q;
    
    rep(i,1,n)
        if(in[i]==0)q.push(i);

    while(!q.empty()){
        int cur = q.top();
        q.pop();
        ans.pb(cur);
        for(auto child:adj[cur]){
            in[child]--;
            if(in[child]==0)q.push(child);
        }
    }
    if(ans.size()==n){
        rep(i,0,n-1)cout<<ans[i]<<" ";

        cout<<endl;
    }
    else cout<<"Sandro fails."<<endl;


}
