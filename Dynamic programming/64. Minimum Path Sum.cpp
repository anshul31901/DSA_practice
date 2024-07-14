class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>cur(m,0);
        vector<int>prev(m,0);
        prev[m-1]=grid[n-1][m-1];
        for(int i = m-2;i>=0;i--){
            prev[i]=prev[i+1]+grid[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(j<m-1){
                    cur[j]= grid[i][j]+min(prev[j],cur[j+1]);
                }
                else cur[j]=grid[i][j]+prev[j];
            }
            prev = cur;
        }
        return prev[0];
    }
};
