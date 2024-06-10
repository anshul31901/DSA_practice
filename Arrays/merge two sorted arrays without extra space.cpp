class Solution {
public:
//gap method
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0;i<n;i++){
            nums1[m+i]=nums2[i];
        }

        int gap = (m+n+1)/2; //ceil


        while(gap){
            for(int i = 0 ;i+gap<m+n;i++){
                if(nums1[i]>nums1[i+gap])swap(nums1[i],nums1[i+gap]);
            }

            gap==1?gap=gap/2:gap = (gap+1)/2;
        }


    }
};



