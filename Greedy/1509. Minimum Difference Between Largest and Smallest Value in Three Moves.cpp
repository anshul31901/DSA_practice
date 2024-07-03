class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)return 0;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();

        // we have to choose between combinations either remove
        // 3 largest elements
        // 1 smallest element and 2 largest ones
        // 2 smallest or 1 largest and so on 
        //note removing 2 smallest means just copy the value of 3rd element to them 
        //similarly for largest removing 3 largest means copying 4th largest values to all of them
        
        

        int ans = INT_MAX;
        for(int i = 0 ;i<4;i++){
            ans = min(ans,nums[n-i-1]-nums[3-i]);
        }
        return ans;

        
    }
};
