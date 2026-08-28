https://leetcode.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        //we go about this in a bfs kind of way 
        int l = 0 , r =0; //initial interval of bfs is only first element
        int jumps = 0 ; //require 0 jumps to reach here 
        int maxReach = 0;

        while(r<n-1){
            //1 bfs cycle
            for(int i = l ; i<=r ; i++){
                maxReach = max(maxReach, i+ nums[i]);
            }
            //once we have found out our max reach from this interval 
            //next interval is from r+1 to maxReach 
            l = r+1;
            r = maxReach;

            jumps++;
        }
        return jumps;
    }
};
