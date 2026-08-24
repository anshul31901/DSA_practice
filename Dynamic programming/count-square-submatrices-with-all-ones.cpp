https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/2118849154/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // dp[i][j] = side length of the largest all-ones square whose
        // bottom-right corner is at matrix[i-1][j-1] (1-indexed, padded)
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int total = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i-1][j-1] == 1){
                    // instead of re-checking a new row + new column by hand,
                    // just read off what's already known at the 3 neighbors
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;

                    // dp[i][j] = k means squares of size 1..k ALL end here,
                    // so this cell alone contributes k to the total count
                    total += dp[i][j];
                }
            }
        }
        return total;
    }
};
