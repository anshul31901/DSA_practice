https://leetcode.com/problems/rotting-oranges/description/

// we will use bfs inseatd of dfs because here minimum time would be obtained if we use dfs

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    
        queue<pair<pair<int,int>,int>>q;
    //pair<int,int> will store the co ordinates of the oranges and the second will store the time taken to rach the orange
        int n = grid.size();
        int m = grid[0].size();
        int ones=0;//no. of fresh oranges in the grid
        int ans=0;//initial ans is zero because if all oranges are rotten or there is no rotten orange we the answer would be zero

      //first we would push all the rotten oranges with their time =0 in the queue because rotting needs to start simultaneously from all rotten oranges
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)q.push({{i,j},0});
                if(grid[i][j]==1)ones++;
            }
        }
        while(!q.empty()){
            auto a =q.front();
            q.pop();
            int r =a.first.first;//row
            int c= a.first.second;//column
            int time = a.second;//time
        //we keep on updating the answer
        //we don't need a visited array for bfs here as rotten oranges would be considered visited and fresh ones would be considered unvisited
         ans = max(ans,time);
            //right
          //if the right element is in bounds and if its fresh we visit it and make it rotten. similar for left up and down.
            if(c+1<m && grid[r][c+1]==1){
               grid[r][c+1]=2;//visited
               ones--;
                q.push({{r,c+1},time+1});
            }
            //left
            if(c-1>=0&&grid[r][c-1]==1){
                grid[r][c-1]=2;
                ones--;
                q.push({{r,c-1},time+1});
            }
            //up
            if(r-1>=0&&grid[r-1][c]==1){
                grid[r-1][c]=2;
                ones--;
                q.push({{r-1,c},time+1});
            }
            //down
            if(r+1<n && grid[r+1][c]==1){
                grid[r+1][c]=2;
                ones--;
                q.push({{r+1,c},time+1});
            }
        }

        return ones==0?ans:-1;
        
    }
};
//time complexity = O(n*m)
//space complexity = O(n*m) reason: if all oranges are rotten we will end up pushing all oranges in queue.
