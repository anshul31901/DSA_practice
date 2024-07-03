//Brute won't work so we will use a maxHeap 
// first sort both the arrays 
// we create a hash set that keeps tabs on what indices sum has been already included in the heap 
// a max heap that has elements like <sum,<idx1,idx2>> and governed by sum


//so what we do is pop the top(largest) element from heap store it in our res
// then we check if (i-1,j ) or (i,j-1) pairs have already been included in our heap if not? take those indices with their sum and  add to the heap

// as soon as we do this operation C times we get C largest sums

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<pair<int,pair<int,int>>>maxH;
    set<pair<int,int>>hash;
    
    
    vector<int>res;
    
    maxH.push({A[n-1]+B[n-1],{n-1,n-1}});
    hash.insert({n-1,n-1});
    
    while(C--){
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
