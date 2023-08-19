https://www.codingninjas.com/studio/problems/topological-sorting_973003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
//we maintain an indegree vector that indicated the number of prerequisites dependencies to a vertice
//we maintain a queue and push all the 0 indegree vertices first into it
//while removing these vertices we also decrease the inegree of their connected edges and if indegree of some edge becomes 0 we also push it into the queue
//if toposort is possible (no. of vertices ==toposort.size())
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
	    vector<int>in(nodes+1);
        vector<vector<int>>adj(nodes+1);
	    for(int i=0;i<edges;i++){
	        int a= graph[i][0];
            int b= graph[i][1];
            adj[a].push_back(b),in[b]++;

	    }
	    vector<int>ans;
	    queue<int>q;
	    for(int i=0;i<nodes;i++){
	        if(in[i]==0)q.push(i);
	    }
	    while(!q.empty()){
	        int x = q.front();
	        ans.push_back(x);
	        q.pop();
	        for(auto child:adj[x]){
	            in[child]--;
	            if(in[child]==0)q.push(child);
	        }
	        
	    }
	    if(ans.size()==nodes)return ans;
	    else return {-1};
}
