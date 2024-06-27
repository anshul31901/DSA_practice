class Solution {
public:
    void solve(vector<int>&hash, vector<int>&temp,vector<vector<int>>&res,vector<int>& nums){


        if(temp.size()==hash.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<hash.size();i++){
            if(hash[i]!=1){
                temp.push_back(nums[i]);
                hash[i]=1;
                solve(hash,temp,res,nums);
                hash[i]=0;
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>hash(nums.size(),0);
        vector<int>temp;
        vector<vector<int>>res;
        solve(hash,temp,res,nums);
        return res;
        
    }
};
