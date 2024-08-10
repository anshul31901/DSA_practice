#include<bits/stdc++.h>
 
using namespace std;
 
vector<int>adj[200001];
vector<int>level(200001,-1);
vector<vector<int>>LCA(200001,vector<int>(18,-1));
 
void dfs(int node, int parent, int lvl){
    LCA[node][0] = parent;
    level[node] = lvl;
 
    for(auto child:adj[node]){
        if(child!=parent){
            dfs(child,node,lvl+1);
        }
    }
}
 
int getLca(int a , int b, int maxN){
    if(level[b]<level[a])swap(a,b);
 
    int d = level[b]- level[a];
 
 
    while(d>0){
        int lift = log2(d);
 
        b = LCA[b][lift];
        d = d-(1<<lift);
    }
    if(a==b)return a;
 
    for(int i = maxN;i>=0;i--){
        if(LCA[a][i]!=-1&&LCA[a][i]!=LCA[b][i]){
            //lca exists and 2ith parents are not equal
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}
 
int getkthparent(int a, int k){
 
    while(a!=-1&&k>0){
        int lift = log2(k);
        a = LCA[a][lift];
        k = k-(1<<lift);
    }
    return a;
}
 
 
int main(){
 
 
    int n,m;
    cin>>n>>m;
 
    // while(m--){
    //     int a,b;
    //     cin>>a>>b;
    //     adj[a].push_back(b);
    //     adj[b].push_back(a);
    // }
 
    for(int i = 2;i<=n;i++){
        int a;
        cin>>a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
 
    dfs(1,-1,0);
    int maxN = log2(n);
 
    for(int i = 1;i<=maxN;i++){
        for(int node = 1;node<=n;node++){
            if(LCA[node][i-1]==-1)LCA[node][i]=-1;
            else{
                int par = LCA[node][i-1];
                LCA[node][i] = LCA[par][i-1];
            }
        }
    }
    // int q;
    // cin>>q;
    // while(q--){
    //     int a,b;
    //     cin>>a>>b;
    //     cout<<getLca(a,b,maxN)<<endl;
 
 
    // }
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<getkthparent(a,b)<<endl;
    }
 
 
 
}
