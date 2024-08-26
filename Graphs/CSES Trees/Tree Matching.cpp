
//greedy appraoch:Just keep matching a leaf with the only vertex adjacent to it while possible.
vector<int>adj[200005];
vector<int>vis(2e5+1,0);

ll ct;

void dfs(int node,int par){

    for(auto child:adj[node]){
        if(child!=par){
            dfs(child,node);
            if(!vis[child]&&!vis[node]){
                ct++;
                vis[child]=1;
                vis[node]=1;
            }
        }
    }

}



//DP approach:


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[200005][2];
vector<int>adj[200005];



//dp[node][0]= max matchings obtained in subtree rooted at node if no edge between a node and child is taken 
//dp[node][1] = max matchings obtained in subtree rooted at node when at most 1 edge from node it its child is obtained


// dp[node][0] = summation for all childs max(dp[child][0],dp[child][1]);
// suppose we take v->u edge
    //dp[v][1]= 1+dp[u][0]     + summmation(max(dp[chiild][0],dp[child][1])) except for u
    //           1+dp[u][0] + dp[v][0]-max(dp[u][0],dp[u][1]);


// for calculating dp[node][1] we need to calculate dp[node][0] first;
// for calculating dp[node][0] we need dp[child][0] and dp [child][1] for all nodes 


void dfs(int node,int par){


    for(auto child:adj[node]){
        if(child!=par){
                dfs(child,node);
                dp[node][0] += max(dp[child][0],dp[child][1]);
        }
        
    
    }
    for(auto child: adj[node]){
        if(child!=par){
            dp[node][1]= max(dp[node][1],1+dp[child][0]+dp[node][0]-max(dp[child][0],dp[child][1]));
        }
    }
    
    

}



int main(){

    int n ;
    cin>>n;
 

    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1]);
    





}
