//push all in max heap 
//row with most vacant seat on top pop it sell its seat ticket, decrement its number by 1 seat and insert it again 
// repeat B times
int Solution::solve(vector<int> &A, int B) {
    priority_queue<int>maxH;
    for(auto it:A){
        maxH.push(it);
    }
    long profit = 0;
    while(B--){
        int temp = maxH.top();
        profit+=temp;
        maxH.pop();
        maxH.push(temp-1);
        
    }
    return profit;
    
    
    
    
}
