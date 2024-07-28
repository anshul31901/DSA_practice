class Solution {
public:
//we cant convert the connected components of the boundary elements so run dfs on the boundary 0's and mark them visited
//now whose 0's in the board that are not visited will be converted and rest will remain the same
    void dfs(int x,int y , vector<vector<int>>&vis,vector<vector<char>>& board){

        vis[x][y]=1;
        int m = board.size();
        int n = board[0].size();

        if(x-1>=0&&vis[x-1][y]==0&&board[x-1][y]=='O'){
            dfs(x-1,y,vis,board);
        }
        if(x+1<m&&vis[x+1][y]==0&&board[x+1][y]=='O'){
            dfs(x+1,y,vis,board);
        }
        if(y-1>=0&&vis[x][y-1]==0&&board[x][y-1]=='O'){
            dfs(x,y-1,vis,board);
        }
        if(y+1<n&&vis[x][y+1]==0&&board[x][y+1]=='O'){
            dfs(x,y+1,vis,board);
        }


    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i =0;i<n;i++){
            if(vis[0][i]==0&&board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(vis[m-1][i]==0&&board[m-1][i]=='O'){
                dfs(m-1,i,vis,board);
            }
        }
        for(int i =0;i<m;i++){
            if(vis[i][0]==0&&board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(vis[i][n-1]==0&&board[i][n-1]=='O'){
                dfs(i,n-1,vis,board);
            }
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(board[i][j]=='O'&&vis[i][j]==0)board[i][j]='X';
            }
        }
     

        
        
    }
};
