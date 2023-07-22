https://leetcode.com/problems/binary-search-tree-iterator/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*>myStack;

    BSTIterator(TreeNode* root) { 
     pushAll(root);   
    }
    
    int next() {
        TreeNode*temp=myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(!myStack.empty()){
            return true;
        }
        else return false;
    }
    void pushAll(TreeNode*root){
            for(;root!=NULL;root=root->left) myStack.push(root);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
