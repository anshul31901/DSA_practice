https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-04

class Solution {
public:
// dp[i][j] = the biggest lead (score advantage) that the player whose turn it is can guarantee, using only piles i through j.

// Now say we have a bigger strip piles[i..j], and it's the mover's turn. The mover has two choices:

// Choice A: take piles[i] (the left pile).

// The mover gains piles[i] stones right now. Then the strip piles[i+1..j] remains, and it's the opponent's turn on that smaller strip.

// Now here's the subtle bit: dp[i+1][j] is defined as "the lead the mover-of-that-subgame can guarantee." But in this scenario, the "mover of that subgame" is our opponent, not us! So:

// dp[i+1][j] = (opponent's stones from i+1..j) − (our stones from i+1..j)

// That's the opposite of what we want to add to our running total. We want:

// (our total lead) = (piles[i] we just took) + (our stones from i+1..j) − (opponent's stones from i+1..j)
//                   = piles[i] + [ −dp[i+1][j] ]
//                   = piles[i] − dp[i+1][j]

// That minus sign isn't arbitrary — it's because dp[i+1][j] is measured from the opponent's point of view, since they're the one moving next on that leftover strip. To flip it to our point of view, we negate it.

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // length 1: base case
        for(int i = 0 ;i<n;i++){
            dp[i][i] = nums[i];
        }
        // length 2, 3, 4, ... up to n       
        for(int len=2; len<=n; len++){
            for(int i = 0 ; i+len-1<n ; i++){
                int j = i+len-1;
                dp[i][j]= max(nums[i]-dp[i+1][j],
                              nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};
