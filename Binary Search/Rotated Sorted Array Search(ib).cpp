//find pivot -> now befor pivot sorted and after it sorted too so apply binary search on both

int findPivot(const vector<int> &A){
    int lo = 0;
    int hi = A.size();
    int n = A.size();
    
    
    
    while(lo<=hi){
        int mid = lo +((hi-lo)>>1);
        
        int next = A[(mid+1)%n];
        int prev = A[(n+mid-1)%n];
        
        if(A[mid]<=prev&&A[mid]<=next){
            return mid;
        }
        else if(A[mid]<=A[n-1]){
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return -1;
}
int binarySearch(const vector<int> &A, int B,int s, int e){

    
    while(s<=e){
        int mid = s+((e-s)>>1);
        
        if(A[mid]==B)return mid;
        else if(A[mid]>B){
            e = mid-1;
        }
        else s = mid+1;
    }
    return -1;
}
int Solution::search(const vector<int> &A, int B) {
    
    int pivot = findPivot(A);
    int n = A.size();
    int i = binarySearch(A,B,0,pivot-1);
    int j = binarySearch(A,B,pivot,n-1);
    
    return i!=-1? i :j;
    
}
