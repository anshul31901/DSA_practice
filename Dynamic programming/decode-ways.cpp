https://leetcode.com/problems/decode-ways/

class Solution {
public:
    bool isValid(char &a, char &b){
        if(a=='0')return false;

        if(a=='1')return true;
        else if(a=='2'){
            if(b>'6')return false;

            return true;
        }
        return false;

    }
    int numDecodings(string s) {
        int n = s.size();
        if(s[0]=='0')return 0;

        vector<int>dp(n+1,0);

        dp[0]=1;

        for(int i = 1; i <= n ; i++){

            if(i-1>=0 && s[i-1]!='0'){
                dp[i] += dp[i-1];
            }
            if(i-2>=0 && isValid(s[i-2],s[i-1])){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};





