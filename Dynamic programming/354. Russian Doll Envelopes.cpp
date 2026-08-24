https://leetcode.com/problems/russian-doll-envelopes/


// Key idea: reduce 2D → 1D LIS via a sorting trick, then reuse standard O(n log n) LIS.

// Steps:

// Sort by width ascending.
// Tie-break: for equal widths, sort height descending (not ascending) — this is the trick.
// Run strictly-increasing LIS on the height sequence alone (tail[] + lower_bound, same as 1D LIS).
// Answer = LIS length.
class Solution {
public:
    static bool comp (vector<int> & a , vector<int> & b ){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
        
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n  = envelopes.size();

        sort(envelopes.begin(), envelopes.end(),comp);

       vector<int>lis;
       lis.reserve(n);

       for(auto &e : envelopes){
        int val = e[1];
        auto it = lower_bound(lis.begin(),lis.end(),val);
        if(it == lis.end())lis.push_back(val);
        else *it = val;
       }

       return lis.size();



    }
};


