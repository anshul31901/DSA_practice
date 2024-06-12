class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur =nums[0];
        int ct =0;
        for(int i =0;i<nums.size();i++){
            if(cur==nums[i])ct++;
            else ct--;

            if(ct==0)cur = nums[i+1];
        }
        return cur;
    }
};
