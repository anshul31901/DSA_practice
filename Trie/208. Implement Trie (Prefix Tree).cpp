https://leetcode.com/problems/implement-trie-prefix-tree/
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
