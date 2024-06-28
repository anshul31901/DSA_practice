//find peak: there is guaranteed peak in edge cases you can put next or prev as -1 if they go out of bounds
//than before peak normal binary search and after it reverse binary search for descending sorted array
int BinarySearch(vector<int> &A,int&B, int s, int e){
    
    while(s<=e){
        int mid = s+((e-s)>>2);
        if(A[mid]==B)return mid;
        else if(A[mid]<B)s= mid+1;
        else e = mid-1;
        
    }
    return -1;
}
int rBinarySearch(vector<int> &A,int&B, int s, int e){
    
    while(s<=e){
        int mid = s+((e-s)>>2);
        if(A[mid]==B)return mid;
        else if(A[mid]<B)e= mid-1;
        else s = mid+1;
        
    }
    return -1;
}
int Solution::solve(vector<int> &A, int B) {
    int s = 0;
    int n = A.size()-1;
    int e = n-1;
    //lets first find bitonic idx
    int peak = -1;
    
    while(s<=e){
        int mid = s+((e-s)>>2);
            int next = -1;
            if(mid+1<n)next = A[mid+1];
            int prev = -1;
            if(mid-1>=0)prev = A[mid-1];
        
        if(A[mid]>prev&&A[mid]>next){
            peak = mid;
            if(A[mid]==B)return mid;
            break;
        }
        else if(A[mid]<next)s = mid+1;
        else e = mid-1;

    }
    
   
    int a = BinarySearch(A,B,0,peak);
    int b = rBinarySearch(A,B,peak,n-1);
    
    if(a==-1&&b==-1)return -1;
    else if(a!=-1)return a;
    else return b;
    
}
