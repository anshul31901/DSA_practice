https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            vp.push_back({__builtin_popcount(arr[i]),arr[i]});
            //__builtin_popcount(int):- returns the number of set bits
        }
        sort(vp.begin(),vp.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(vp[i].second);
        }
        return ans;
        
    }
};
