//n!logn for recursion so we don't use recursion
//instead we use this for 0 indexing do k--
// then k/(n-1)! gives such that us idx se start hoga hamara kth permutation
// k = k%(n-1)! gives the nex value of k ...wrt prev step us idx se start hone vaala (new) k th permutaion is our ans
// then we remove that idx from array  add it to ans and calcuate new idx in remaining arr
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>nums;
        string ans = "";

        for(int i =1;i<n;i++){
            fact*=i;
            nums.push_back(i);

        }
        nums.push_back(n);
        k--;
        while(!nums.empty()){
            ans = ans + to_string(nums[k/fact]);
            nums.erase(nums.begin()+(k/fact));
            k = k%fact;
            if(nums.size()>0)fact/=nums.size();

            
        }
        return ans;

    }
};
