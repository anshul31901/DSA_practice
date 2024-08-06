good explenation: https://algo.monster/liteproblems/1223

#define ll long long 

class Solution {
public:
    int MOD = 1e9+7;
    int solve(int idx,int last,int freq, int n,vector<int>& rollMax,vector<vector<vector<int>>>&dp){
        // if we have made a n length sequence
        if(idx>=n)return 1;
        ll total = 0;
        if(last!=-1&&dp[idx][last][freq]!=-1)return dp[idx][last][freq];
        for(int face = 1; face<=6 ; face ++){
            

            if(face != last){
                total = (total + solve(idx+1,face,1,n,rollMax,dp))%MOD;
            }
            else{
                if(freq<rollMax[face-1]){
                    total = (total + solve(idx+1,face,freq+1,n,rollMax,dp))%MOD;
                }
            }
        }
        return dp[idx][last][freq]=total;

    }
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(7,vector<int>(51,-1)));
        return solve(0,0,0,n,rollMax,dp);
    }
};
