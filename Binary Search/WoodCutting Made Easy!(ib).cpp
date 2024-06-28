//mid between 0 and max tree height and we cut at mid
// if wood =b means we cut at optimal height and return mid
//if wood >b means possible ans bt we neet to cut even higher so s = mid+1;
//if wood<b means we need to cut low means e = mid-1;

//wood value can be calcuated by a helper fxn in O(n) time so complexity is O(logn)
long calculateCut(vector<int> &A, int C){
    long cut = 0 ;
    for(int i =0;i<A.size();i++){
        if(A[i]>C)cut +=A[i]-C;
    }
    return cut;
}
int Solution::solve(vector<int> &A, int B) {
    int s = 0 ;
    int e = 0 ;
    for(int i =0;i<A.size();i++){
        e  = max(e,A[i]);
    }
    long cut = 0 ;
    int ans = 0;
    
    while(s<=e){
        int mid = s+((e-s)>>2);
        
        cut = calculateCut(A,mid);
        
        if(cut==B){
            return mid;
        }
        else if(cut>B)s=mid+1,ans=mid;
        else e = mid-1;
    }
    return ans;

}
