#include<bits/stdc++.h>
using namespace std;


vector<int>adj[200005];
vector<int>vis(2e5+1,-1);

#define ll long long int

//subordinates of parent = (1+subordibates of child)//for each child
int dfs(int node){
    vis[node]=0;

    for(auto child:adj[node]){
        if(vis[child]==-1){
            vis[node]+=(1+dfs(child));
        }
    }
    return vis[node];
}



int main(){

    int n ;
    cin>>n;

    for(int i =2;i<=n;i++){
        int x;
        cin>>x;

        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1);
    for(int i = 1;i<=n;i++){
        cout<<vis[i]<<" ";
    }





}
