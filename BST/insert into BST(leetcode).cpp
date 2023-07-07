https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)return new TreeNode(val);
        TreeNode*cur=root;

        while(cur){
            if(val>cur->val&&cur->right==NULL){
                cur->right=new TreeNode(val);
                return root;
            }
            else if(val<cur->val&&cur->left==NULL){
                cur->left= new TreeNode(val);
                return root;
            }

            if(val>cur->val){
                cur=cur->right;
            }
            else cur=cur->left;
        }
        return root;
        
    }
};


//recursive solution
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)return new TreeNode(val);
        if(val>root->val){
            root->right=insertIntoBST(root->right,val);
            
        }
        if(val<root->val){
            root->left=insertIntoBST(root->left,val);
        }
        return root;

        
    }
};
