class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
  
        
        vector<int>cur(n,0);
        vector<int>prev(n,0);

        for(int i =0;i<n;i++){
            prev[i]=grid[0][i];
        }
        for(int i =1;i<n;i++){
            for(int j =0;j<n;j++){
                if(j==0){
                    cur[j]= grid[i][j]+min(prev[j],prev[j+1]);
                }
                else if(j<n-1)cur[j]= grid[i][j]+min(prev[j+1],min(prev[j-1],prev[j]));
                else cur[j]=grid[i][j]+min(prev[j],prev[j-1]);
            }
            prev = cur;
        }
        int ans = INT_MAX;
        for(int i =0;i<n;i++){
            ans = min(prev[i],ans);
        }
        return ans ;
        
    }


};
