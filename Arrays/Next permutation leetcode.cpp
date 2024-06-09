class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = -1;
        int idx2 =-1;


        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx1 = i;
                break;
            }

        }
        cout<<idx1<<" ";

        if(idx1==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i]>nums[idx1]){
                idx2 = i;
                break;
            }
        }
        cout<<idx2<<" ";
        swap(nums[idx1],nums[idx2]);
        cout<< endl<<nums[idx1]<<" "<<nums[idx2]<<endl;
        reverse(nums.begin()+idx1+1,nums.end());
        for(int i =0;i<nums.size();i++) {
            cout<<nums[i]<<" "<<endl;
        }
        return;
      
    }
};
