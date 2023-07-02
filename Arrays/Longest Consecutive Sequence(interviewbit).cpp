https://www.interviewbit.com/problems/longest-consecutive-sequence/
int Solution::longestConsecutive(const vector<int> &A) {
    vector<int>v;
    for(int i=0;i<A.size();i++){
        v.push_back(A[i]);
    }
    sort(v.begin(),v.end());
    int ans=1;
    int maxi=1;
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1]==v[i]+1){
            ans++;
        }
        else if(v[i]==v[i+1])continue;
        else ans=1;
        
        maxi=max(ans,maxi);
    }
    return maxi;
}
