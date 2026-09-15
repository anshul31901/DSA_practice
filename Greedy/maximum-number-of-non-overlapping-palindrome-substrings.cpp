https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/?envType=daily-question&envId=2026-09-15

//i assume must have read my dp soln for this

// from start of string we'll take smallest palindromes that suffice us and search the remaining 

// Intuition for greedy :

// check all even and odd centres form 0 
//     find first valid palindrome from left and reduce search space


// initialise start = 0 and end = n-1;
//  left se centers select karo for (odd centred left = right) and for (even right = left +1)
//    e.g  0 0 (odd), 0 1(even) , 1 1(odd) , 1 2 (even)
//    center = 0  , l = center /2 = 0 , r = l+centr%2 =1 
//    l ki max value n-1 --> center bounded by 2*(n-1)

//  as soon as we find palindrome start = right +1 (reduced search space --> ab iske right ke hi dhundenge so as non overlapping )

//complexity O(n)2 sc = O(1)

class Solution {
public:

    int maxPalindromes(string s, int k) {
        int n = s.size()-1;
        int ans = 0;
        int start = 0;

        for(int centre = 0 ; centre<=2*n ; centre++){

            int l = centre/2;
            int r = l + (centre%2);

            while(l>=start && r<=n && s[l]==s[r]){
                if(r-l+1>=k){
                    ans++;
                    start = r+1;
                    break;
                }
                l--;
                r++;
            }
        }
        return ans;



    }
};
