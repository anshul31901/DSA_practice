https://www.codingninjas.com/studio/problems/920469?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<vector<pair<int,int>>>adj(vertices);
    for(int i=0;i<edges;i++){
        int x = vec[i][0];
        int y = vec[i][1];
        int wt = vec[i][2];
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});

    }
    vector<int>dist(vertices,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        int cur_d=pq.top().first;
        int cur_node= pq.top().second;

        pq.pop();

        for(auto child:adj[cur_node]){
            int v = child.first;
            int wt = child.second;

            if(cur_d+wt<dist[v])
            {
                dist[v]=cur_d+wt;
                pq.push({dist[v],v});
            }
        }    
    }
    return dist;

}
