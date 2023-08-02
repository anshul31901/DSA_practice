https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>res;
        solve(s,0,path,res);
        return res;

    }
//we assume before the index string has been divided into proper partitions and after the index we have to divide it into partitions
//the partitions of a string are stored in path and all the possible partitioning schemes are stored in res
//we run a loop i:from idx to n-1: if the substring(idx,i) is palindrome we make its partitiona nd then recursively call fxn from i+1;
//meaning that i tak partition ban gaya ab i ke aage;
//when i is last idx of string and we make its partition the funxtion call we will do will have idx = n; therefore we know we have successfully done partitioning and we push back path to res
    void solve(string s,int idx, vector<string>&path,vector<vector<string>>&res){
        if(idx==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx,i)){
                path.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,path,res);
                path.pop_back();
            }

        }

    }
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){return false;}

            start++;
            end--;
        }
        return true;
    }

};
