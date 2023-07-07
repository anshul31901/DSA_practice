https://leetcode.com/problems/delete-node-in-a-bst/submissions/988630873/

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
class Solution {
public:
    TreeNode* find_rightmost(TreeNode*root){
        TreeNode*ans;
        while(root){
            ans=root;
            root=root->right;
        }
        return ans;
    }
    TreeNode* helper(TreeNode*root){
        if(!root->left){
            return root->right;

        }
        if(!root->right)return root->left;
        TreeNode* rchild=root->right;
        TreeNode* left_rightmost=find_rightmost(root->left);
        left_rightmost->right=rchild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        TreeNode*dummy=root;
        while(root){
            if(root->val==key)return helper(root);
            if(key>root->val){
                if(root->right&&root->right->val==key){
                    root->right=helper(root->right);
                    return dummy;
                }
                root=root->right;
                continue;
            }
            else{
                if(root->left&&root->left->val==key){
                    root->left=helper(root->left);
                    return dummy;
                }
                else root=root->left;continue;
            }
        }
        return dummy;

    }
        
    
};
Console
