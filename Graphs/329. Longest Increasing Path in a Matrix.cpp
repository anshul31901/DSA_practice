class Solution {
    public:

    void dfs(vector<vector<int>>& matrix,vector<vector<int>>&dp,int x,int y){

        dp[x][y]=1;
        int n = matrix.size();
        int m = matrix[0].size();

        int dx[] = {-1 , 0, 1, 0};
        int dy[]= {0, 1, 0, -1  };


        for(int i =0;i<4;i++){

            int p = x+dx[i];
            int q = y+dy[i];
            if(p>=0&&p<n&&y+q>=0&&q<m&&matrix[p][q]>matrix[x][y]){
                if(dp[p][q]==-1){
                    dfs(matrix,dp,p,q);
                }
                dp[x][y]=max(dp[x][y],1+dp[p][q]);
            }
        }


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        int maxt = 1;

        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(dp[i][j]==-1){
                    dfs(matrix,dp,i,j);

                }
                maxt = max(maxt,dp[i][j]);
            }
        }
        return maxt;
        
    }
};
