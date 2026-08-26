//j-i is bound to decrease  and min height is bottleneck so we target to increase that because its our best shot at getting answer better than current one
class Solution {
public:
    int maxArea(vector<int>& nums) {

        int i = 0;
        int j = nums.size()-1;
        int maxWater = 0;
        while(i<j){
            int h = min(nums[i],nums[j]);
            maxWater = max(maxWater, h*(j-i));

            if(nums[i]>=nums[j])j--;
            else i++;
        }
        return maxWater;
        
    }
};
