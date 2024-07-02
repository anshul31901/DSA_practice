//now because duplicate elements are present in the array  we can say that median must have at least >= (N*M)/2+1 elements 
// e.g     1 2 2 3 3 3 3 3 5 now median here is 3 if we calculate elements less than 3 there are therefore we need to operate on <= criteria 
// we need to find the least element that has >=(N*M)/2 +1 predicate be like F F F F T T T T need to find first true
// s = 1 and e = 1e9 acc to element ranges given to us
// now for every mid in each row we check elements <= mid  and add the value for each row (calculate for whole matrix)
// if successful find even lesser mid , if not increase mid
#define ll long long 

int helper(vector<int>&A,int k ){
    
    int s = 0;
    int n = A.size();
    int e = n-1;
    int ans = 0;
    
    
    while(s<=e){
        
        int mid = s+((e-s)>>1);
        
        if(A[mid]<=k){
            ans = mid+1;
            s = mid+1;
            
            
        }
        else e = mid-1;
        
    }
    return ans;
    
}
int Solution::findMedian(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int N = (n*m)/2+1;
    
    
    
    int s = 1;
    int e = 1e9;
    int ans = 0;
    
    while(s<=e){
        int mid = s+((e-s)>>1);
        
        int ct = 0;
        for(int i =0;i<n;i++){
            ct+=helper(A[i],mid);
        }
        
        if(ct>=N){
            ans = mid;
            e = mid-1;
        }
        else s = mid+1;
    }
    return ans ;
    
    

    
    
}
