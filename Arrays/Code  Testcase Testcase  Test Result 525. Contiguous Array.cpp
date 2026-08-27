class Solution {
https://leetcode.com/problems/contiguous-array/description/
public:
    int findMaxLength(vector<int>& nums) {
        //we maintain del freq[1]-freq[0] and map it to leftmost index

        //now at every place we wanna know like if at that pt del = 5 nums[1]-nums[0]=5 we'd want to subtract 5 nums i from array spo well look forleftmost index with del and if found remove that subarray with del 5 completely 

        // e.g 0 1 0 -> del = -1 0 -1-->0(leftmost is always 0) [-1,0] or -1 [0,-1]
        int n = nums.size();
        unordered_map<int,int>mp;
        int sz = 0;
        mp[0]=0;

        int zeros = 0;
        int ones = 0;
        for(int i = 1; i <=n ;i++){
            if(nums[i-1]==0)zeros++;
            else ones++;
            int del = ones-zeros;

            if(mp.find(del)!=mp.end()){
                sz = max(i-mp[del],sz);
            }
            else mp[del] = i;
        }

        return sz;
        



    }
};
