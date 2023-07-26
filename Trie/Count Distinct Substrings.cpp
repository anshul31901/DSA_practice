https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0
#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode*links[26];

    TrieNode* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,TrieNode*node){
        links[ch-'a']=node;
    }
    bool containsKey(char ch){
        return(links[ch-'a']!=NULL);
    }
};
//approach is if in a root trie node we keep on adding the substring starting from idx 0,then idx 1, then idx 2
//and for e.g abcab 

//iteration 1:-
//starting from idx 0 i.e. strings starting from char a ,when we start adding from idx 0 to n it looks like
 //a->b->c->a->b count+=5 and it covers substrings a,ab,abc,abca,abcab

//iteration 2:-
// now adding ro root from idx 1 i.e. strings starting by char b : b->c->a->b->c
//covers strings b,bc,bca,bcab   count+=4 i.e.9

//iteration 3:-
//now similarly for c  c->a->b;  adds strings c,ca,cab count+=3 i.e.12

//iteration 4:-
//when we come to next idx it is b again which is already added to root so we traverse to b's trie instead of incrementing
//the next char is a  which is also present in b's trie so we also traverse to it instead of adding new character
//this case represents that the strings b,ba are already covered

//iteration 5:- similar as above

//so count = 12+1(null string);


int countDistinctSubstrings(string &s)
{   
    int cnt=0;
    TrieNode*root=new TrieNode();
    int n= s.size();
    for(int i=0;i<n;i++){
      //from 1 to n each index we start adding chars to root of the trie
        TrieNode*node=root;
        for(int j=i;j<n;j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j],new TrieNode());
            }
            node=node->get(s[j]);
        }
    }
    return cnt+1;
}
