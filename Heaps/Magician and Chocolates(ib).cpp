int Solution::nchoc(int A, vector<int> &B) {
    int mod = 1e9+7;
    priority_queue<int>maxH;
    
    for(auto i:B){
        maxH.push(i);
    }
    
    long long choco = 0;
    while(A--){
        int temp = maxH.top();
        maxH.pop();
        choco = (choco + temp)%mod;
        maxH.push(temp/2);
    }
    return choco;
}
