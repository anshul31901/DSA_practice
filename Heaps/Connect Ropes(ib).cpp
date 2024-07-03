//create min heap 
// remove top 2 elements add their sum to min heap and cost;
//until only one rope/element remains in the heap
int Solution::solve(vector<int> &A) {
    // min heap 
    priority_queue<int,vector<int>,greater<int>>pq;
    
    for( auto it:A){
        pq.push(it);
    }
    
    long cost = 0 ;
    
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cost += (a+b);
        pq.push(a+b);
        
    }
    return cost;
    
}
