vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<pair<int,pair<int,int>>>maxH;
    set<pair<int,int>>hash;
    
    
    vector<int>res;
    
    maxH.push({A[n-1]+B[n-1],{n-1,n-1}});
    hash.insert({n-1,n-1});
    
    while(n--){
        auto temp = maxH.top();
        maxH.pop();
        res.push_back(temp.first);
        int i = temp.second.first;
        int j = temp.second.second;
        
        if(hash.find({i-1,j})==hash.end()){
            maxH.push({A[i-1]+B[j],{i-1,j}});
            hash.insert({i-1,j});
        }
        if(hash.find({i,j-1})==hash.end()){
            maxH.push({A[i]+B[j-1],{i,j-1}});
            hash.insert({i,j-1});
        }
        
    }
    return res;
}
