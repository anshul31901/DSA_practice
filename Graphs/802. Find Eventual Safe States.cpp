//reverse the edges . now the node with terminal nodes(0 outdegree) will be the one with 0 indegree in the new graph
//in original graph paths with cycles will be the one's that won't reach terminal nodes. we can traverse with terminal nodes as source and ignoring cycle nodes
//store toposort of the graph with terminal nodes

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>in(n,0);
        vector<int>adj[n];

        for(int i =0;i<n;i++){
            for(auto a:graph[i]){
                adj[a].push_back(i);
                in[i]++;
            }
        }
        vector<int>res;

        queue<int>q;
        for(int i =0;i<n;i++){
            if(in[i]==0){
                q.push(i);       
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for(auto child:adj[cur]){
                in[child]--;
                if(in[child]==0)q.push(child);
            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};
