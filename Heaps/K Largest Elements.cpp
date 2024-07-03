vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int,vector<int>,greater<int>>minH;
    
    for(auto it:A){
        minH.push(it);
        if(minH.size()>B)minH.pop();
        
        
    }
    vector<int>res;
    while(B--){
        res.push_back(minH.top());
        minH.pop();
    }
    return res;
}
