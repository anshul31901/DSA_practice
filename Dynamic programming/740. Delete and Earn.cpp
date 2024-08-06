
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        vector<int>val(1e4+1,0);
        //1 2 2 3 4 5
        //val 1:1 2:4 3:3 4:4 5:5
        //if i take only this number what val would i get since i can take same number further
        for(auto i:nums){
            val[i]+=i;
        }
        dp[i]: if i take this as my max element what would be my final sum. we canot take i-1's but can take i-2's
        vector<int>dp(1e4+1,0);
        dp[1]= val[1];
        int ans = 0;
        for(int i = 2;i<1e4+1;i++){
            dp[i] = max(dp[i-1],dp[i-2]+val[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
        
    }
};
