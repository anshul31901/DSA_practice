//Nlog K complexity just store the <val,<row,col>> in min heap ;
//push 1st col in min heap that would have the least element surely
// when we pop it out we also get the row and col of the lease element so we push the next element from the same row to min heap i.e.<A[row][col+1],<row,col+1>>
// now surely the next element on top will be smallest becasuse heap has all the right k contendors for it
//then we repeat the steps until heap is empty 
// instead of nklog(nk) we get ans in nklogK
vector<int> Solution::solve(vector<vector<int> > &A) {
    //create a min heap
    int k = A.size();
    int n = A[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int>res;
    
    for(int i = 0 ;i<k;i++){
        pq.push({A[i][0],{i,0}});
    }
    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();
        res.push_back(temp.first);
        int row = temp.second.first;
        int col  = temp.second.second;
        if(col<n-1)pq.push({A[row][col+1],{row,col+1}});
    }
    return res;
    
}
