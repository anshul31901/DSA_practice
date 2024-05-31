int Solution::singleNumber(const vector<int> &A) {
    int ans =0;
    
    for(int i =0;i<32;i++){
        int ct=0;
        for(int j=0;j<A.size();j++ ){
            if(A[j]&(1<<i))ct++;
        }
        if(ct%3!=0)ans+=(1<<i);
        
    }
    return ans;

}
