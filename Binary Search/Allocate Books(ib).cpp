//pre
#define ll long long int 
bool predicate(vector<int> &A, int B,ll limit){
    
    int ct =0;
    ll x = limit;
    
    for(int i =0;i< A.size();i++){
        if(limit<A[i]||ct>B)return false;
        
        if(x<A[i]){
            ct++;
            x = limit;
            
        }
        
        x-=A[i];
    }
    ct++;
    if(ct<=B)return true;
    else return false;
    
    
    
}
int Solution::books(vector<int> &A, int B) {
    if(B>A.size())return -1;
    ll sum = 0;
    for(auto it:A){
        sum+=it;
    }
    // cout<<sum<<endl;
    ll s =0;
    ll e = sum;
    ll ans = -1;
    
    while(s<=e){
        ll mid = s +((e-s)>>1);
        // cout<<s<<" "<<e<<" "<<mid<<endl;
        
        if(predicate(A,B,mid)){
            ans = mid;
            // cout<<mid<<endl;
            e = mid-1;
        }
        else s = mid+1;
    }
    return ans;
}
