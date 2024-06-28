int Solution::solve(vector<int> &A, int B) {
    
    int s = 0;
    int e = A.size()-1;
    if(B>=A[e])return e+1;
    int ans = 0;
    while(s<=e){
        int mid = s+((e-s)>>2);
        if(A[mid]<=B)s= mid+1;
        else {
            ans = mid;
            e = mid-1;
        }
    }
    return ans;
}
