// dp[i][j] = ways to choose j non-overlapping segments using points 0..i
// if we dont include i , means skip it : dp[i-1][j]
// but if we take it there can be i segments of length 1,2,3...i so we need sum(dp[i-l][j-1]);
// example dp[3][2] = skip + dp[2][1] +  dp[1][1] ....upto dp[0][1]
//                           (1 length)   (2 length).   try to draw on paper or relate to tc 1
// we'll maintain a prefix and update that at each iteration 
class Solution {
public:
    const int MOD = 1e9+7;
    int numberOfSets(int n, int k) {


        vector<vector<int>>dp(n,vector<int>(k+1,0));
        vector<int>prefixSegment(k,0);
        prefixSegment[0] = 1;

        for(int i = 0 ; i<n ; i++){
            dp[i][0]=1;
        }

        for(int i = 1; i<n;i++){
            for(int j = 1 ; j<=k ; j++){
                int skip = dp[i-1][j];
                int take = prefixSegment[j-1];
                dp[i][j] = (take+skip)%MOD;
                prefixSegment[j-1] = (prefixSegment[j-1]+dp[i][j-1])%MOD;
            }
        }

        return dp[n-1][k];
        
    }
};
