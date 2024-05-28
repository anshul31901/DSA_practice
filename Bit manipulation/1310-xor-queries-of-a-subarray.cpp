class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>hash(arr.size());
        hash[0]=arr[0];
        for(int i =1;i<hash.size();i++){
            hash[i]=hash[i-1]^arr[i];
        }
        vector<int>ans;

        for(auto q:queries){
            if(q[0]==0)ans.push_back(hash[q[1]]);
            else ans.push_back(hash[q[0]-1]^hash[q[1]]);
        }
        return ans;
    }
};
