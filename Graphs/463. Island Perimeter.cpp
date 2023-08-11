https://leetcode.com/problems/island-perimeter/description/

//approach is simple we use similar like flood fill algorithm
//we notice that if the grid we call for is out of bounds or its value is 0 we add an edge.
//if it is unvisited we call recurively for it and make it visited by putting its value =2
//and then call the function for up,down,left,right blocks
class Solution {
public:
    void solve(vector<vector<int>>& grid,int i,int j,int&ct){
        int n= grid.size();
        int m= grid[0].size();
        if(i<0||i>=n||j<0||j>=m){
            ct++;
            return;
        }
        if(grid[i][j]==0){
            ct++;
            return;
        }
        if(grid[i][j]==2)return;
        grid[i][j]=2;

        //up
        solve(grid,i-1,j,ct);
        //left
        solve(grid,i,j-1,ct);
        //down
        solve(grid,i+1,j,ct);
        //right
        solve(grid,i,j+1,ct);

    }
 
    int islandPerimeter(vector<vector<int>>& grid) {
        int edges=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    solve(grid,i,j,edges);
                    break;
                }
            }
        }
        
        return edges;

    }
};
