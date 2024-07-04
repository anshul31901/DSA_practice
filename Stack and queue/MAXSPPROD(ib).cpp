//stack se o(n) me hoha becaus eke element ko ek hi bar pop aur push kr skte hain nested loop me baar baar vahi comparisons hote stack me ek bar me hi eliminate
#define ll long long int
int Solution::maxSpecialProduct(vector<int> &A) {
    stack<int>st;
    long mod = 1e9+7;
    int n = A.size();
    vector<int>left(n);
    
    for(int i = 0;i<n;i++){
        
        while(!st.empty()&&A[st.top()]<=A[i]){

            st.pop();
        }
        if(st.empty()){
            left[i]=-1;
        }
        else left[i]=st.top();
        
        st.push(i);
        
    }
    st = stack<int>();
    vector<int>right(n);
    
    for(int i = n-1;i>=0;i--){
        
        while(!st.empty()&&A[st.top()]<=A[i]){

            st.pop();
        }
        if(st.empty()){
            right[i]=-1;
        }
        else right[i]=st.top();
        
        st.push(i);
        
    }
    long long int maxi = 0;
    
    for(int i =0;i<n;i++){
        if(left[i]==-1||right[i]==-1)continue;
        else maxi = max(maxi,1ll*left[i]*right[i])%mod;
    }
    return maxi;
    
    
    
    
}
