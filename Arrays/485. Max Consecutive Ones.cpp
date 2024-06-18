//till element is 1 increment count when its 0 set ct =0, calculate maxi everytime
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct =0;
        int maxi =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==1)ct++,maxi = max(ct,maxi);
            else ct =0;
        }
        return maxi;
    }
};
