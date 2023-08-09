https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/
//for a tree SSSD(single source shortest distance ; first store shortest distance by normal dfs in (i did it in visited array) and the then for the available proposals calculate the min one.
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define pb push_back
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'

void dfs(int v,vii &vis,vvi &adjecency_list,int dist){
    vis[v].ff=1,vis[v].ss=dist;
    for(auto child:adjecency_list[v])
        if(vis[child].ff!=1)
            dfs(child,vis,adjecency_list,dist+1);
}
int main()
{
    int n;
    (n+1);
    cin>>n;
    int e = n-1;
    vvi adjecency_list(n+1);
    vii vis(n+1,{0,INT_MAX});

    while(e--){
        int a,b;
        cin>>a>>b;
        adjecency_list[a].pb(b);
        adjecency_list[b].pb(a);
    }
    
    int dist =0;
    

    dfs(1,vis,adjecency_list,dist);
    int ans=-1;
    int mini=INT_MAX;

    int q;
    cin>>q;
    while(q--){
        int girl;
        cin>>girl;
        if(vis[girl].ss<mini){
            ans = girl;
            mini=vis[girl].ss;
        }
        else if(vis[girl].ss==mini){
            ans =min(ans,girl);
        }
    }
    cout<<ans;




}
