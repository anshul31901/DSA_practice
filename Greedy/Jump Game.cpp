https://leetcode.com/problems/jump-game/submissions/2122392752/
//dp solution is O(n^2) //we go greedy !!

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;// initially we at 0 index

        //maxReach is i + nums[i] and if max reach is n-1 above we return true
        // if for any i maxReach is less than i we return false as we cant reach this i 


        for(int i = 0 ; i<n ; i++){
            if(maxReach<i)return false;
            maxReach = max(maxReach,i+nums[i]);
            if(maxReach>=n-1)return true;
        }
        return maxReach>=n-1;
    }
};
