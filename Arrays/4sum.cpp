#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>temp;
        vector<vector<int>>res;
        if(nums.size()<4)return {};
        for(int i =0;i<nums.size()-3;i++){
            for(int j = i+1;j<nums.size()-2;j++){
                long long  t = 1ll*target - 1ll*nums[i]-1ll*nums[j];
                int s =j+1;
                int e = nums.size()-1;

                while(s<e){
                   temp.clear();
                   if(1ll*nums[s]+1ll*nums[e]==t){
                    temp.push_back(nums[i]),temp.push_back(nums[j]),temp.push_back(nums[s]),temp.push_back(nums[e]);
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    s++,e--;
                    }
                    else if(1ll*nums[s]+1ll*nums[e]>t){
                     e--;
                     }
                     else s++;
                }
            }

        }
        for(auto it:st){
            res.push_back(it);
        }
        return res;
    
    }
        
    
};
