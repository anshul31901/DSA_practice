    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
    bool isSafe(int node,int color,vector<int>&col,bool graph[101][101], int m ,int n){
        for(int i=0;i<n;i++){
            if(i!=node&&graph[node][i]==1&&col[i]==color){
                return false;
            }
        }
        return true;
    }
    bool solve(int node,vector<int>&col,int m,int n,bool graph[101][101]){
        //body of code
        if(node==n)return true;
        for(int i=1;i<=m;i++){
            if(isSafe(node,i,col,graph,m,n)){
                col[node]=i;
                if(solve(node+1,col,m,n,graph))return true;
                else col[node]=0;
                
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>col(n,0);
        return solve(0,col,m,n,graph);
    }
};
