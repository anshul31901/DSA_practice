class Solution {
public:

void solve(int idx,int target,vector<int>temp,vector<int>& candidates,set<vector<int>>&s){
    if(target==0){
        sort(temp.begin(),temp.end());
        s.insert(temp);
        return;
    }
    else if(idx==candidates.size()||candidates[idx]>target)return;


    temp.push_back(candidates[idx]);
    solve(idx,target-candidates[idx],temp,candidates,s);
    temp.pop_back();
    solve(idx+1,target,temp,candidates,s);
    return;

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>s;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,target,temp,candidates,s);

        vector<vector<int>>res;
        for(auto it: s){
            res.push_back(it);
        }
        return res;
    }
};
