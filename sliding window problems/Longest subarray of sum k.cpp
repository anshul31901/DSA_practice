https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//we have a o(n^2)brute force solution which is just take a loop 2 times
//first we move towards naive sliding window solution
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        //ans is the variable that will store the length of longest subarray
        int ans =0;
      //initially we set both pointers at 0
        int i,j=0;
        int sum=0;
        while(j<N){
          //while we store the sum in sliding window and increment it till sum>=k.
           sum+=A[j];
          //if sum<k we remove elements from the window from backwards by incrementing i till sum <k or it hits k.
          while(sum>K&&i<j){
              sum=-A[i];
              i++;
          }
          //if sum==k we update answer variable
           if(sum==K){
               ans=max(ans,j-i+1);
           }
           j++;
        }
        
        return ans;
        
        
        
    } 

};
// this apprach will not work when negative numbers are included in the sliding window for e.g size: 17 K:15
//A[]= -13 0 6 15 16 2 15 -12 17 -16 0 -3 19 -3 2 -9 -6
//Because if we find sum <k we increment by moving j forward, if we find sum>k we decrement the window by moving i forward.But in case of negative numbers we need to
//remove elements by decrementing j also try above example

//Better approach
//if we map sum till the idx to idx  sum(i,j)=sum(0,j)-sum(0,i-1).
//from 0 to n-1 in every iteration we update current prefix sum (map its earliest occuring value to earliest index that produces this valuea) and check if mp[sum-k] exists.
//if it exists update ans =max(ans,cur idx-mp[sum-K].



class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        long long sum=0;
        int ans=0;
        //maps the sum to earliest index
        map<long long,int>mp;
        for(int i=0;i<N;i++){
                    
            sum+=A[i];
        //as we move fron idx 0 to n
        //we want to store the earliest index to maximise the length value :if it already exists we will use the lesser idx value         
            if(mp.find(sum)==mp.end())mp[sum]=i;
            
            if(sum==K)ans= max(ans,mp[sum]+1);
        //if mp[sum-K] exists we must have stored its earliest index in map and will calculate current idx-mp[sum-K];
            if(mp.find(sum-K)!=mp.end())ans= max(ans,abs(i-mp[sum-K]));
        }
        

        
        return ans;
        
    } 

};
//Time complexity=O(N)
//space complexity=O(N)



