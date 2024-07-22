class Solution {
public:
    int minDistance(string s, string t) {

        int m = s.size();
        int n = t.size();

       vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i =0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int j =0;j<=n;j++){
            dp[0][j]=j;
        }

        for(int i =1;i<=m;i++){
            for(int j =1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    //match
                    dp[i][j]= dp[i-1][j-1];
                }
                else{
                    //1. replace s[i] to t[j]
                    int replace = 1+dp[i-1][j-1];
                    //2. delete s[i]
                    int del = 1+dp[i-1][j];
                    //3. add char ros rop=> ros|p rop
                    int add = 1+dp[i][j-1];

                    dp[i][j]= min(add,min(replace,del));
                }
            }
        }
        return dp[m][n];


        
    }
};
//space optimisation:
class Solution {
public:
    int minDistance(string s, string t) {

        int m = s.size();
        int n = t.size();

        vector<int>prevRow(n+1);

        for(int j =0;j<=n;j++){
            prevRow[j]=j;
        }
        vector<int>curRow(n+1);
        

        for(int i =1;i<=m;i++){
            curRow[0]=i;
            for(int j =1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    //match
                    curRow[j]=prevRow[j-1];
                }
                else{
                    //1. replace s[i] to t[j]
                    int replace = 1+prevRow[j-1];
                    //2. delete s[i]
                    int del = 1+prevRow[j];
                    //3. add char ros rop=> ros|p rop
                    int add = 1+curRow[j-1];

                    curRow[j]= min(add,min(replace,del));
                }
            }
            prevRow=curRow;
        }
        return prevRow[n];


        
    }
};
