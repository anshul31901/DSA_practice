class Solution {
public:
    // int f(int i,vector<int>& nums,vector<int>&dp){
    //     if(i>=nums.size())return 0;
    //     if(dp[i]!=-1)return dp[i];

    //     int rob = nums[i]+f(i+2,nums,dp);
    //     int next = f(i+1,nums,dp);
    //     return dp[i]= max(rob,next);
    // }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int n = nums.size();
        dp[0]=0;
        dp[1]= nums[0];

        for(int i =2;i<dp.size();i++){
            dp[i]= max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];

        
    }
};
