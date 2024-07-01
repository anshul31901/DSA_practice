class Solution {
// if arr[mid] != next and prev its unique element
//if its first element of pair  2 cases : if no. of elements behind it is  even then they are pairs of duplicates too so s = mid+2 //search in righ and keep numbers odd 
//                                         else if its odd then e = mid-1 search left hal
// vice verca for last element in pair
public:
    int singleNonDuplicate(vector<int>& nums) {

        int s = 0;
        int n = nums.size();
        int e = n-1;
        if(n==1)return nums[0];

        while(s<=e){
            int mid = s +((e-s)>>1);

            int prev  = nums[(n+mid-1)%n];
            int next = nums[(mid+1)%n];


            if(nums[mid]!=prev&&nums[mid]!=next)return nums[mid];
            else if(nums[mid]!=next){
                if((e-mid)%2==0)e = mid-2;
                else s = mid+1;
            }
            else{
                if((mid-s)%2!=0)e = mid-1;
                else s= mid+2;
            }
            
        }
        return -1;



        
    }
        
};
