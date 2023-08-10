https://leetcode.com/problems/number-of-islands/submissions/
class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        if(i<0 || j<0 ||i>=n ||j>=m) return;
        if(grid[i][j]=='0'||grid[i][j]=='2')return;
        grid[i][j]='2';
        //left
        dfs(i,j-1,grid);
        //right
        dfs(i,j+1,grid);
        //up
        dfs(i-1,j,grid);
        //down
        dfs(i+1,j,grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        int ic=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ic++;
                }
            }
                
        }
        return ic;
    }
};
