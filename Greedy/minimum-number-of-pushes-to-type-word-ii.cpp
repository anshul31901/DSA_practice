//https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2026-07-31
class Solution {
public:
// store freqs 
// store uniques 
// 8 uniques once ->next uniques 2 


//sort by highest to lowest freq
//highest freq  placed earlier  so weight to access them is low 
// exact mapping of which char has which freq doesnt matter to the answer - we would just need how many disctinct chars are there 
//descending in order of their freq
    int getWeight(int uniq){
        if(uniq%8)return (uniq/8) +1;
        else return (uniq/8);
    }
    int minimumPushes(string word) {
        // 0-8 =1
        // 9-16 = 2
        // 16-24 = 3
        // 24-26 = 4
        int res = 0;
        vector<int>freq(26,0);

        for(auto c : word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i = 0 ; i<26;i++){
            int weight = getWeight(i+1);
            res += (weight*freq[i]);
        }

        return res;
    }

// uniq
// weight 
// freq

};
