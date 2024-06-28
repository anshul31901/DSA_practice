int Solution::findCount(const vector<int> &A, int B) {
    int r=-1;//of element just greater than B
    int l = -1;// of element just smaller than B
    
    int n = A.size()-1;
    if(B==A[n])r = n+1;
    
    
    if(r==-1){
        int s =0;
        int e = n;
        
        int mid = s+((e-s)>>2);
        while(s<=e){
            mid =s+((e-s)>>2);
            
            if(A[mid]<=B)s = mid+1;
            else {
                r = mid;
                e = mid-1;
            }
        }
        
    }
        int s =0;
        int e = n;
        
        int mid = s+((e-s)>>2);
        while(s<=e){
            mid =s+((e-s)>>2);
            
            if(A[mid]>=B)e = mid-1;
            else {
                l = mid;
                s=mid+1;
            }
        }
        
        return r-l-1;
    
}
