class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>temp;
        vector<vector<int>>res;
        for(int i =0;i<nums.size();i++){

            int target = 0 - nums[i];
            int s =i+1;
            int e = nums.size()-1;

            while(s<e){
                temp.clear();
                if(nums[s]+nums[e]==target){
                    temp.push_back(nums[i]),temp.push_back(nums[s]),temp.push_back(nums[e]);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    s++,e--;
                }
                else if(nums[s]+nums[e]>target){
                    e--;
                }
                else s++;
            }
        }
        for(auto it:st){
            res.push_back(it);
        }
        return res;
    
    }

};
