https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

//in this question we assume our sliding window contaiins a substring wgich only has unique characters so
//while j we increase the frequency of s[j] in the map signifying that we included that element in our window ans compute max size.
// if we come accross j such that after m[s[j]]++ the the frequency of s[j]>1 mwans we do not have unique character . so be start removing elements fron the back of the window.
// so while(s[j]>0)we decrease m[s[i]] and then increment i till each character has only one occurence.
//always dry run on an example.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        map<char,int>mp;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;

            while(mp[s[j]]>1&&i<j){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};
