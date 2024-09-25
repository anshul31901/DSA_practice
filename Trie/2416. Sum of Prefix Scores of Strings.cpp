//using unordered map

//store every possible  prefixe's frequency for each word . 
// after that for a word count the frequencies of all of its prefixes and that is our answer
unordered_map<string,int>mp;

   for(auto word: words){

      string temp = word;
      while(temp!=""){
          mp[temp]++;
          temp.pop_back();
      }
   }

  

  vector<int>res;

  for(auto word: words){
      int score = 0;

      string temp = word;

      while(temp!=""){
          if(mp.find(temp)!= mp.end()){
              score += mp[temp];
          }
          temp.pop_back();
      }
      res.push_back(score);
  }
  return res;


// Trie approach: somehow uses less complexity same logic
struct Trie{

    Trie* links[26];
    int count= 0;

};
class Solution {
public:
    int getCount(Trie* root, string& word){

        int res = 0;
        Trie* node = root;

        for( auto ch : word){
            node = node->links[ch-'a'];
            res+= node->count;
        }
        return res;

    }
    vector<int> sumPrefixScores(vector<string>& words) {

        Trie* root = new Trie();

        for(auto word : words){
            Trie* node = root;
            for(auto ch: word){
                if(node->links[ch-'a']==NULL){
                    node->links[ch-'a']= new Trie();
                }
                node = node->links[ch-'a'];
                node->count++;
            }
        }

        vector<int>res;
        for(auto word: words){
            res.push_back(getCount(root,word));
        }
        return res;

        
    }
};



