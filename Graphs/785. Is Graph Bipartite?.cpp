https://leetcode.com/problems/is-graph-bipartite/submissions/
//approach 1 = using 2 dfs one for colouring and one for checking if the graph is bipartite

class Solution {
public:
    void dfs(int v,vector<vector<int>>& graph,vector<int>&color,int c){
        color[v]=c;

        for(auto child:graph[v]){
            if(color[child]==-1)dfs(child,graph,color,1-c);
        }
    }
    bool check_dfs(int v,vector<vector<int>>& graph,vector<int>&color,vector<int>&vis){
      vis[v]=1;
      for(auto child:graph[v]){
          if(color[child]==color[v])return false;
      }
      for(auto child:graph[v]){
          if(vis[child]==0)return check_dfs(child,graph,color,vis);
      }
      return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)dfs(i,graph,color,1);
        }

        vector<int>vis(n,0);
        int ans = true;

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(check_dfs(i,graph,color,vis)==false)return false;
            }
        }
        return true;

        
    }
};
