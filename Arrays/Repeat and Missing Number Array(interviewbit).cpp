#define ll long long int
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int sum =0;
    long long int s_sum = 0;
    int n = A.size();
    for(int i =0;i<A.size();i++){
        sum+=A[i];
        s_sum+= (1ll*A[i])*A[i];
    }
    
    ll d1 = sum-(1ll*n)*(n+1)/(2*1ll);
    ll d2 = s_sum - (1ll*n)*(n+1)*(2*n+1)/(6*1ll);
    
    ll a = (d2/d1 +d1)/2;
    ll b = d2/d1 - a;
    
    vector<int>ans;
    ans.push_back((int)a);
    ans.push_back((int)b);
    return ans;
    
    
    
}

// s - n(n+1)/2;
// a -b

// a2-b2= s_sum - n(n+1)(2n+1)/6;

// a+b = diff2/diff1
// a-b = diff1

// 2*a = diff2/diff1+diff1
