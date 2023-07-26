https://leetcode.com/problems/implement-trie-prefix-tree/
#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node*links[26];
    int cntEndWith =0;
    int cntPrefix=0;

    bool containsKey(char ch){return (links[ch-'a']!=NULL);}

    Node* get(char ch){return links[ch-'a'];}

    void put(char ch,Node*node){links[ch-'a']=node;}

    void increaseEnd(){cntEndWith++;}

    void increasePrefix(){cntPrefix++;}

    void deleteEnd(){cntEndWith--;}

    void reducePrefix(){cntPrefix--;}

    int getEnd(){return cntEndWith;}

    int getPrefix(){return cntPrefix;}

};

class Trie{
    private:Node*root;

    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node*node = root;
      //for every char in the word if it exists in the trie we go to its trie and increase count prefix else we insert it in trie and do the same
      //and at the end of the word we increase countEndWith that indicated the end of the word and frequency of the word
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();

    }
//we just traverse the word if the chars exist in trie we traverse it to the end and return endWith in the end 
//else if the char doesn't exist in the trie we return 0;
    int countWordsEqualTo(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else return 0;
        }
        return node->getEnd();
    }
//same as above but we just return the count prefix at the end
    int countWordsStartingWith(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
            }
            else return 0;
        }
        return node->getPrefix();
    }
//we traverse the word and correspionding to each char trie we decrease its count prefix and in the end we decrease the endwith as we delete the word
    void erase(string &word){
        // Write your code here.
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            
        }
        node->deleteEnd();
    }
    
};
