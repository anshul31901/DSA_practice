//create a min heap of size k while pushing elements one by one when size>k pop the top element ie smallest 
// at last top element will be kth largest element
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minH;

        for(int i =0;i<nums.size();i++){
            minH.push(nums[i]);

            if(minH.size()>k)minH.pop();
        }
        return minH.top();
    }
};
