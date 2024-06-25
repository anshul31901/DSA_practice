#include<bits/stdc++.h>
class Solution {
public:
    void solve(int idx,int target,vector<int>& candidates,vector<int>&temp, vector<vector<int>>&s){
        if(target ==0){
           
            s.push_back(temp);
            return;
        }
        else if(idx==candidates.size()||candidates[idx]>target)return;
        int prev =-1;
        for(int i =idx;i<candidates.size();i++){

     
            if(candidates[i]!=prev){
                prev= candidates[i];
                temp.push_back(candidates[i]);
                solve(i+1,target-candidates[i],candidates,temp,s);
                temp.pop_back();
            }

        }

        return;

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>s;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,temp,s);
        // vector<vector<int>>res;
        // for(auto it:s){
        //     res.push_back(it);
        // }
        return s;
    }

};
