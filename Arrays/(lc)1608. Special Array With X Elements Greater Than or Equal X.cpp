class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int>hash(1001,0);
        for(auto i:nums){
            for(int j =0;j<=i;j++){
                hash[j]++;
            }

        }
        for(int i =0;i<1001;i++){
            if(hash[i]==i)return i;
        }
        return -1;
        
    }

};
//binary search soln = n log n 
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      
        int end = nums.size()-1;
        int max = nums[end];

        for(int i =0;i<=max;i++){
            int s =0;
            int e =end;
            int ans =-1;
            int mid = s +(e-s)/2;
            while(s<=e){
                mid = s+(e-s)/2;
                if(nums[mid]<i)s=mid+1;
                else{
                    ans = mid;
                    e=mid-1;
                }

            }
                if(ans!=-1&&nums.size()-ans==i)return i;
                else if(ans==-1&&nums.size()==i)return i;           
        }
        return -1;
        
    }





};
