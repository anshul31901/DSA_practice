https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxi=0;
        for(int i=0;i<K;i++){
            maxi+=Arr[i];
        }
        long temp=maxi;
        
        
        for(int i=K;i<N;i++){

            
            temp+=Arr[i];
            temp-=Arr[i-K];
            maxi=max(temp,maxi);
        }
        return maxi;
    }
};
