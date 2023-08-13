https://www.codingninjas.com/studio/problems/detect-cycle-in-an-undirected-graph-_758967?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


//very unoptimised code but see to optimise it later
//we call dfs for every node suct that the node that calls dfs for its child is its parent. So, we maintain the visited array as the parent array
//we see to it like the node that has no parent i.e. the node from which we first call the dfs is root node and its parent is itself.
//for example starting 0 we call dfs we mark its parent as 0 then we see that 1 is unvisited so we call dfs for 1 with 0 as parent.
//how we detect a cycle-- if in the middle of the dfs for a node a we find connected node b that is alrady visited but it is not the parent of a.
//It indicated that to a we have more than one path to a either than its parent so that indicated a cycle.
class Graph {

public:
    bool dfs(int v,vector<int>&par,vector<int>adj[],int parent)
    {
        par[v]=parent;
        for(auto child:adj[v]){
            if(par[child]==-1){
                if (dfs(child,par,adj,v)==true)return dfs(child,par,adj,v);
            }
            else if(child!=par[v])return true;
        }
        return false;
    }
    
    bool detectCycle(int V, vector<int> adj[]) {
      vector<int>par(V,-1);
      int ans = false;
      for(int i=0;i<V;i++){
        //the root node will be the parent for itself and we have to check all the connected components
          if(par[i]==-1){
              ans = ans||dfs(i,par,adj,i);
          }
      }
      return ans;


    }
};
