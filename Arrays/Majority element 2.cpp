class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ct1 =0;
        int ct2=0;
        int e1=INT_MIN;
        int e2 = INT_MIN;

        for(int i =0;i<nums.size();i++){
            if(ct1==0&nums[i]!=e2){
                ct1++;
                e1=nums[i];
            }
            else if(ct2==0&&nums[i]!=e1){
                ct2++;
                e2 = nums[i];
            }
            else if(nums[i]==e1)ct1++;
            else if(nums[i]==e2)ct2++;
            else ct1--,ct2--;
        }
        int val = nums.size()/3;
        ct1=0,ct2=0;

        for(int i =0;i<nums.size();i++){
            if(nums[i]==e1)ct1++;
            if(nums[i]==e2)ct2++;

        }
        vector<int>res;
        if(ct1>val)res.push_back(e1);
        if(ct2>val)res.push_back(e2);

        return res;

    }
};
