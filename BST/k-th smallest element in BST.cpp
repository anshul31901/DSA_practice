https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/

class Solution {
public:
    void inorder_helper(int&i,int k,int&ans,TreeNode*root){
        if(root==NULL)return;
        if(i==k)return;
        inorder_helper(i,k,ans,root->left);
        ++i;
        if(i==k){
            ans=root->val;
            return;
        }
        inorder_helper(i,k,ans,root->right);

        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int i=0;
        inorder_helper(i,k,ans,root);
        return ans;

        
    }
};
