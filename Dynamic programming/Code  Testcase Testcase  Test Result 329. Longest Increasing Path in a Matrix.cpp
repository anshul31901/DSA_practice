
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
//we use dfs with dp to calculate lis
//we dont need a visited array for dfs because its deterministic due to constraints that if we wont be visiting a node mor than once.

//since its increasing dfs if we go x1-->x2-->x3 we cant visit x2 or x1 from x3(i.e any parent from a child)

// and also for multiple dfs we are storing results in dp table so a cell is not visited more than 

// TC : each cell visited once : O(m*n)
// SC : O(m*n) , recursions stack ; O(m*n) worst case single lis spanning whole graph
class Solution {
public:
    int m, n;
    vector<vector<int>>*grid;
    vector<vector<int>>dp;

    bool isValid(int i, int j){
        if(i<0||i>=m||j<0||j>=n)return false;

        return true;
    }

    int dfs(int i, int j){
        int lis = 1;
        auto &matrix = *grid;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int k = 0 ; k<4 ; k++){
            int x = i+ dx[k];
            int y = j + dy[k];

            if(isValid(x,y)&& matrix[x][y]>matrix[i][j]){

                if(dp[x][y]!=0){
                    lis = max(lis,1+dp[x][y]);
                }
                else{
                    lis = max(lis,1+dfs(x,y));
                }
            }
        }
        return dp[i][j] = lis;


    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        grid = &matrix;

        dp.assign(m,vector<int>(n,0));

        int res = 0;

        for(int i = 0 ; i <m ; i++){
            for(int j = 0 ; j <n ; j++){
            //dp[i][j] = max length of lis starting from cell (i,j)
                if(dp[i][j]==0){
                    res = max(res,dfs(i,j));
                }
            }
        }
        return res;    
    }
};
