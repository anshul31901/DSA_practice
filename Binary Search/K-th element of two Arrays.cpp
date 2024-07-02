// same as median of 2 sorted array  just this time we keep k elements in left partition
// also initialisation is different
// as sum should be k 
//low is max(0,k-n); e.g k is 5 and  3 ,4 are sizes of array is we assign low to 0 then not enough elements in nums2 therefore at least 1 element should be of nums1
// same as hi is min(k,n) because at max k can be taken from nums 1;
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if(n>m){return kthElement(nums2[],nums1[],m,n,k);}



        //numbers are in terms of how many elements we will include of each

        int s = 0;
        int e = k;


        while(s<=e){
            int mid1 = s+((e-s)>>1);

            int mid2 = k-mid1;

            int l1 = INT_MIN,l2= INT_MIN;
            int r1 = INT_MAX,r2=INT_MAX;

            if(mid1<n)r1 = nums1[mid1];
            if(mid2<m)r2 = nums2[mid2];

            if(mid1-1>=0)l1 = nums1[mid1-1];
            if(mid2-1>=0)l2 = nums2[mid2-1];


            if(l1<=r2&&l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2){
                e=mid1-1;
            }
            else s = mid1+1;




        }
        return 0;
        
    }        
    
};
