https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/?purpose=login&source=problem-page&update=google


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
//mark node visited and in its list call dfs for unvisited nodes
void dfs(int v,vi &vis,vvi &adjecency_list){
    vis[v]=1;
    for(auto child:adjecency_list[v])
        if(vis[child]!=1)
            dfs(child,vis,adjecency_list);
}
int main()
{
    int n,e;
    (n+1);
    cin>>n>>e;
    vvi adjecency_list(n+1);
    vi vis(n+1,0);

    while(e--){
        int a,b;
        cin>>a>>b;
        adjecency_list[a].pb(b);
        adjecency_list[b].pb(a);
    }
    int cc_count=0;
  //as calling dfs for one node marks all of the nodes in cc visited. how many such calls are needed
    for(int i=1;i<=n;i++){
        if(vis[i]==0)dfs(i,vis,adjecency_list),cc_count++;
    }
    cout<<cc_count;



}
