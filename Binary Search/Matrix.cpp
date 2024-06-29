int getRow(vector<vector<int> > &A, int B){
    int n = A.size();
    int m = A[0].size();
    
    int s = 0;
    int e = n-1;
    int row = -1;
    
    while(s<=e){
        int mid = s +((e-s)>>2);
        
        
        if(A[mid][m-1]>=B)row = mid, e= mid-1;
        else s = mid+1;
        
        
    }
    return row;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    
    int row = getRow(A,B);
    if(row==-1)return 0;
    
    int s = 0;
    int e = m-1;
    while(s<=e){
        int mid = s +(e-s)/2;
        if(A[row][mid]==B)return 1;
        else if(A[row][mid]>B)e= mid-1;
        else s = mid+1;
    }
    return 0;
        

}
