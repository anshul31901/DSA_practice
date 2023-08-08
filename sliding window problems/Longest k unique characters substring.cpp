https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

//we create a map mapping the characters to its frequency 
//while increasing j add m[s[j]]++ .if its not present put it in map .and if its present increase its frequency
//the unique characters will be counted by mp.size().
//so if mp.size()==k ans=max(j-i+1,ans);
//if(mp.size()>k) remove elements from map by increaseing i.


class Solution{
  public:
    int longestKSubstr(string s, int k) {
     map<char,int>mp;
     int i=0,j=0;
     int ans=-1;
     while(j<s.size()){
        mp[s[j]]++;
         //if we have more unique elements starti removing elements from back
         while(mp.size()>k&&i<j){
             mp[s[i]]--;
             
             if(mp[s[i]]==0){mp.erase(s[i]);}
             i++;
             
         }
       //if we got k unique elements calculate size
         if(mp.size()==k){ans = max(ans,j-i+1);}
         j++;
     }
     return ans;
     
    }
};
