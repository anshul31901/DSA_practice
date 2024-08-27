class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int mini = nums[0];
        stack<pair<int,int>>st;



        for(int i =1;i<nums.size();i++){
            while(!st.empty()&&nums[i]>st.top().second){
                st.pop();
            }

            if(!st.empty()&&nums[i]<st.top().second&&nums[i]>st.top().first)return true;

            st.push({mini,nums[i]});
            mini = min(mini,nums[i]);
        }
        return false;
        
    }
};
