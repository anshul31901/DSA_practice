//shitty constraints so just take ll as C[i}*b can overflow
//in predicate function we need to check if for this t A painters can do the job
// for that we need to make sure each painter does not take more than t time to do its job and we then can simultaneously assign these painters and successfully complete the job
// predicate function will be like  FFFFFFTTTTTTTT where left false values indication that either its too less time that its even less than time required to paint a particular long wall by a painter
// or we just require more than A painters
// as time increase right trues indicating this time is enough
// we need to find the least True time and modulo it woth 1e8+7 that is the only meaning of the qus constraint 
#define ll long long 
ll mod = 10000003;
bool predicate(int A, int B, vector<int> &C,ll mid ){
    int painter =1;
    ll x = 0;
    
    for(int i =0;i<C.size();i++){
        if(1ll*C[i]*B>mid)return false;
        
        if((x+1ll*C[i]*B)>mid){
            x = 0 ;
            painter++;
            
        }
        x += (1ll*C[i]*B);
        if (painter>A)return false;
        
    }
    return true;
    
}
int Solution::paint(int A, int B, vector<int> &C) {
    
    ll s = 0;
    ll e = 1e18;
    ll ans = 0;
    
    
    while(s<=e){
        ll mid = s+((e-s)>>1);
        
        if(predicate(A,B,C,mid)){
           ans = mid;
           e = mid-1; 
        }
        else s = mid+1;
        
    }
    return ans%mod;
    
}
