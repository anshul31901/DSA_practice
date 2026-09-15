https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/?envType=daily-question&envId=2026-09-15

Note : there is a greedy soln as well which is better but dp one is still same complecity and worth knowing 
greedy one in that folder


// dp[j] = max no of non overlapping substrings whith length >=k in form 1 to j lengthed 
// if we dont take any substring ending at j (skip) i.e skip case dp[j-1]
// if we wanna include j in a substring since min length of a substring is k
//  take case : for every i from 1 to ( j-k) if (i+1,j) is a palindrome dp[j] = max(1+dp[i])
  //  but that we can see 1 and j have 2 for loops and inside 2nd loop checking palindrome is also O(n) so its O(n3) not acceptable

// so we make some optimisations 
// 1st optimisation . do dymanic programming for palindrome calculation (letc call it matrix):
  //      for every s,e where s<=e 
  //         m[s][e] ==1 if  string[s] == string[e] and m[s+1][e-1]==1 
  // (base case is 1 length m[i][i]=1 )

// now our loopup for palindrome takes O(1) everytime 


// 2nd optimisation : we'll explore  take only k and k+1 length palindrome 
// reason  string *********aaa|abba|aaa****** so lets say a big string and k was 4
// a palindrome that is very big (odd one will have odd centre  and even one will have even centre ) e.g  aaa|abba|aaa here has abba
// out of those centres k and k+1 cover minimum odd and even lengthed palindorme cases acceptable by us 
// but why ?  *********aaa|abba|aaa****** : taking minimum valid one here abba leaves us more space at left and rigt
// those extra left and right chars we saved by not taking any bigger palindrome will contribute to more possible ones
// its guaranteed that by taking min needed well if not more will get at least same ans as taking a big one 

// so that saves us another O(n) now our complexity is calculate isPalindrome(n^2) + O(n) our dp solution is O(n^2)

// for every j : either skip(dont include j in any palindrome)  or 
//  check if i= j-k and i= j-( k+1 ) palindrome i to j then dp[j] = 1+dp[i]
class Solution {
public:

    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>>isPalindrome(n+1,vector<bool>(n+1,0));

        for(int i = 1 ; i <=n ; i++){
            isPalindrome[i][i]=1;
            if(i+1<=n&&s[i-1]==s[i])isPalindrome[i][i+1]=1;
        }

        for(int i = n ; i>=1 ; i--){
            for(int j = i+2; j<=n ; j++){
                if(s[i-1]==s[j-1] && isPalindrome[i+1][j-1])isPalindrome[i][j]=1;
            }
        }



        vector<int>dp(n+1,0);

        for(int j = 1; j<=n ; j++){
            dp[j]=dp[j-1];//skip
            for(int l = 0 ; l<=1;l++){
                int i = j-(k+l);
                if(i>=0 && isPalindrome[i+1][j]){
                    dp[j] = max(dp[j],1+dp[i]);
                }
            }
        }
        return dp[n];


    }
};
