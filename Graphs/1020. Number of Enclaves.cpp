class Solution {
public:

//similar to ques surrounded region
    void dfs(int x,int y , vector<vector<int>>&vis,vector<vector<int>>& board){

        vis[x][y]=1;
        int m = board.size();
        int n = board[0].size();

        if(x-1>=0&&vis[x-1][y]==0&&board[x-1][y]==1){
            dfs(x-1,y,vis,board);
        }
        if(x+1<m&&vis[x+1][y]==0&&board[x+1][y]==1){
            dfs(x+1,y,vis,board);
        }
        if(y-1>=0&&vis[x][y-1]==0&&board[x][y-1]==1){
            dfs(x,y-1,vis,board);
        }
        if(y+1<n&&vis[x][y+1]==0&&board[x][y+1]==1){
            dfs(x,y+1,vis,board);
        }


    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i =0;i<n;i++){
            if(vis[0][i]==0&&grid[0][i]==1){
                dfs(0,i,vis,grid);
            }
            if(vis[m-1][i]==0&&grid[m-1][i]==1){
                dfs(m-1,i,vis,grid);
            }
        }
        for(int i =0;i<m;i++){
            if(vis[i][0]==0&&grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(vis[i][n-1]==0&&grid[i][n-1]==1){
                dfs(i,n-1,vis,grid);
            }
        } 
        int ct=0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1&&vis[i][j]==0)ct++;
            }
        }
        return ct;      
        
    }
};
