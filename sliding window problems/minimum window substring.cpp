https://leetcode.com/problems/minimum-window-substring/description/


class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "";
        }
        pair<int,int>ans={-1,-1};

  //first we map all characters to t to their occurence     
        map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
         int i=0,j=0;
  //initially the length of smallest substring is INT_MAX
        int mn=INT_MAX;
  //count of unique characters
        int count=mp.size();

        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
          //if after decreasing the frequency becomes 0 we decrease count
                if(mp[s[j]]==0)count--;
            }

        //count ==0 signifies that we have acquired target substring and we want will calculate if its minimum till now.
        //if map of any char is negative means we have that element in excess and we want to remove it but if in order to remove it we disrupt count from 0 we won't remove it
        //mp[s[j]]<0 measn we have s[j] in excess//to obtain min substring we 
            while(mp.find(s[j])!=mp.end() && mp[s[j]]<0&&i<j){
                if(mp.find(s[i])!=mp.end()){
                   //if we come accross an element that we still need we will not move past it.
                  //but if we can remove it we will remove it.
                    if(mp[s[i]]>=0)break;

                    mp[s[i]]++;
                    
                }
                i++;
            //if i is on a character that isn't on map we will increase i till i belongs to one of the characters that we need.
            while(mp.find(s[i])==mp.end()&&i<j){
                i++;
              
            }               

            }
          //similar as above but for s[i]
           while(mp.find(s[i])!=mp.end() && mp[s[i]]<0&&i<j){
                if(mp.find(s[i])!=mp.end()){
                    if(mp[s[i]]>=0)break;

                    mp[s[i]]++;
                    
                }
                i++;
            while(mp.find(s[i])==mp.end()&&i<j){
                i++;
            }

            }           



            while(mp.find(s[i])==mp.end()&&i<j){
                i++;
            }

            // cout<<i<<" "<<j<<endl;
    //count ==0 signifies that we have acquired target substring and we want will calculate if its minimum till now.
            if(count==0){
                if(mn>=j-i+1){
                    ans={i,j};
                    mn=j-i+1;
                }
                
            }
            j++;
            //cout<<i<<" "<<j<<endl;
        }
        int l=ans.first;
        int h = ans.second;
        if(l==-1 || h==-1) return "";
        string res = s.substr(l,h-l+1);
        return res;
    }
};
