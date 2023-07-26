https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1
#include <bits/stdc++.h> 
 struct Node{
     Node*links[26];
     bool flag;

     bool containsKey(char ch){
         return (links[ch-'a']!=NULL);
     }
//inserts the given node in the reference of given character
     void put(char ch,Node*node){
         links[ch-'a']=node;
     }
     void setEnd(){
         flag = true;
     }
     bool isEnd(){
         return flag;
     }
     Node* get(char ch){
         return links[ch-'a'];
     }
 };
class Trie {
private : Node*root;
public:
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        
    }
    
    bool search(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return false;
            else node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node*node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))return false;
            else node=node->get(prefix[i]);
        }
        return true;      
    }
//this function just checks if all of the prefixes to the string exist in the array of strings
    bool checkIfPrefixExist(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            node = node->get(word[i]);
            if(!node->isEnd())return false;
        }
        return true;;
    }
    

};

string completeString(int n, vector<string> &a){
    Trie trie;
  //first we create an object of the Trie class and insert every string into it
    for(auto &it: a){trie.insert(it);}
    string ans="";
  //for every string
    for(auto &it:a){
      //1.if all prefixes of the string exist in the array 
      //2.ts size > current ans replace answer with it
      //3.else if this string and ans have same size choose lexicographicallly smaller
        if(trie.checkIfPrefixExist(it)){
            if(it.size()>ans.size()){
                ans = it;
            }
            else if(ans.size()==it.size()&&it<ans){ans=it;}
        }
    }
    if(ans=="")return "None";
    return ans;
}
