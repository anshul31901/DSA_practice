#define ll long long int
int calculateDays(ll &wt,vector<int> &A){
    
    ll x = wt;
    int days = 0;
    
    for(int i =0;i<A.size();i++){
        if(x<A[i]*1ll||x==0){
            days++;
            x=wt;
            
        }
        if(A[i]*1ll>wt)return 1e6;
        
        x-=A[i]*1ll;

        
        
    }
    days++;
    return days;
    
}
int Solution::solve(vector<int> &A, int B) {
    ll s =0;
    ll e = 1ll*(*max_element(A.begin(), A.end()))*A.size();
    
    ll mid = s + 1ll*((e-s)>>2);
    int res = 0;
    
    while(s<=e){
        ll mid = s + 1ll*((e-s)>>2);
        int days = calculateDays(mid,A);
        
        if(days<=B){
            res = mid;
            e = mid-1;
        }
        else if(days>B){
            s = mid+1;
            
        }
        
    }
    return res;
    
    
}
