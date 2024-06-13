
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>s;

        for(auto it:nums){
            s.insert(it);
        }
        int ct = 1;
        int maxi = 1;
        for(auto it:s){
            ct=1;
            if(s.find(it-1)==s.end()){
                int x = it;
                while(s.find(x+1)!= s.end()){
                    x++;
                    ct++;
                }

            }
            maxi = max(ct,maxi);
        }
        return maxi;
        
    }
};
