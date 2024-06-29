vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    int s =0;
    int n = A.size();
    int e = n-1;
    int l = -1;
    int r = -1;
    
    while(s<=e){
        int mid = s +((e-s)>>2);
        
        
            if(A[mid]==B){
                l = mid;
                e = mid-1;
            }
            else if(A[mid]>B)e= mid-1;
            else s = mid+1;
        
        
    }
    s = 0;
    e = n-1;
    while(s<=e){
        int mid = s +((e-s)>>2);
        
        
            if(A[mid]==B){
                r = mid;
                s = mid+1;
            }
            else if(A[mid]>B)e= mid-1;
            else s = mid+1;
        
        
    }
    return {l,r};
    
}
