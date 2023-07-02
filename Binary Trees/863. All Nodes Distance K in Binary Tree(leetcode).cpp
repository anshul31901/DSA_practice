https://leetcode.com/problems/count-complete-tree-nodes/submissions/984388091/
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
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lht = lh(root);
        int rht = rh(root);
        if(lht==rht)return (1<<lht)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int lh(TreeNode*root){
        int lh=0;
        while(root){
            lh++;
            root=root->left;
        }
        return lh;
    }
        int rh(TreeNode*root){
        int rh=0;
        while(root){
            rh++;
            root=root->right;
        }
        return rh;
    }
};
