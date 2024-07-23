/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* create(Node*node,map<Node*,Node*>&hash){
        
        if(hash.find(node)!=hash.end())return hash[node];

        Node*root = new Node();
        root->val = node->val;
        hash[node]=root;

        for(auto child:node->neighbors){
            root->neighbors.push_back(create(child,hash));
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return nullptr;
        map<Node*,Node*>mp;
        return create(node,mp);


        
    }
};
//1 [2 4]
//1 

