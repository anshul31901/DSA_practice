// just gotta revrse the directed edges. such graph is called revrsed graph
// Then you store each node's children by dfs and all sorted because all those children would be ancestors in original graph
class Solution {
public:
    void bfs(int node,vector<vector<int>>&graph,vector<vector<int>>&res){
        queue<int>q;
        q.push(node);
        vector<int>vis(graph.size(),0);
        vis[node]=1;

        while(!q.empty()){
            int t = q.front();
            for(auto child : graph[t]){
                if(vis[child]!=1){
                    q.push(child);
                    res[node].push_back(child);
                    vis[child]=1;
                }

            }
            q.pop();
        }
        
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>res(n);

        vector<vector<int>>graph(n);

        for(auto e:edges){
            graph[e[1]].push_back(e[0]);
        }
        for(int i = 0;i<n;i++){
            bfs(i,graph,res);
        }
        for(int i =0;i<n;i++){
            sort(res[i].begin(),res[i].end());
            
        }
        return res;


    }
};
