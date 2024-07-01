https://www.spoj.com/problems/AGGRCOW/


//predicate function is given a dist can we place cows with this min dist gap
//if yes we search for even larger dist
//if no search for a smaller dist
//as dist increases initially speaking predicate function will be like TTTTT but after a certain dist it will be FFFF
// so we just have to find the max true
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pb push_back
#define rep(i) for(int i=0;i<n;i++)

//predicate function
bool canPlace(vector<int>&stall,int c,int dist){

    int last_pos = -1;

    for(int i =0;i<stall.size();i++){
        if(last_pos==-1||stall[i]-last_pos>=dist){
           c--;
           last_pos=stall[i];
        }  
        
        if(c==0)return true;      
    }
    return false;

}


void solve(){
    int n,c;
    cin>>n>>c;
    vector<int>stall(n);

    for(int i =0;i<n;i++){
        cin>>stall[i];

    }

    sort(stall.begin(),stall.end());

    int lo = 0;
    int hi = 1e9;

    int ans = 0;

    while(lo<=hi){
        int mid = lo +((hi-lo)>>2);

        if(canPlace(stall,c,mid)){
            lo = mid+1;
            ans = mid;
        }
        else hi = mid-1;
    }

    cout<<ans<<endl;





  


}






int main()
{
    int t ;
    cin>>t;
    while(t--){
        solve();
    }


}



