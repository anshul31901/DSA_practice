class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        map<int,int>ngs;
        stack<int>st;

        for(int i = nums2.size()-1;i>=0;i--){

            while(!st.empty()&&nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty())ngs[nums2[i]]=-1;
            else ngs[nums2[i]]= st.top();

            st.push(nums2[i]);
        }
        vector<int>res;
        for(int i =0;i<nums1.size();i++){
            res.push_back(ngs[nums1[i]]);
        }
        return res;

        
    }
};
