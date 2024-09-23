https://leetcode.com/problems/extra-characters-in-a-string/description/
class Solution {
public:
    int solve( int i , string &s , set<string>&words , vector<int>& dp){
        int n = s.size();
        if( i == n )return 0;

        if(dp[i]!=-1)return dp[i];

        int match = INT_MAX;
        // finding words starting form j in dictionary
        string temp = "";

        for(int j = i;j<n;j++){
            temp.push_back(s[j]);
            if(words.find(temp)!=words.end()){
                match = min(match,solve(j+1,s,words,dp));
            }
        }

        int skip = 1+ solve(i+1,s,words,dp);

        return  dp[i] = min(match,skip);
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        set<string>words;
        int n = s.size();
        for( auto it: dictionary){
            words.insert(it);
        }
        vector<int>dp(n,-1);
        return solve(0,s,words,dp);


        
    }
};
