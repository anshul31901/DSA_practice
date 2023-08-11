https://leetcode.com/problems/number-of-provinces/description/
class Solution {
public:
    void dfs(int v,vector<vector<int>>&graph,vector<int>&vis){
        vis[v]=1;
      //condition useful for finding childs that are not visited
        for(int i=0;i<graph.size();i++){
            if(i!=v&&graph[v][i]==1&&vis[i]==0)dfs(i,graph,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      
        int n= isConnected.size();
        vector<int>vis(n,0);
        int ct=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ct++;
                dfs(i,isConnected,vis);
            }
        }
        return ct;

    }
};
