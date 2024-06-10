class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int a = nums[0];
        int slow = nums[a];
        int fast = nums[nums[a]];
        while(slow!= fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
