https://leetcode.com/problems/recover-binary-search-tree/

class Solution {
public:
    TreeNode*prev;
    TreeNode*first;
    TreeNode*middle;
    TreeNode*last;

    void inorder(TreeNode* root){
        if(root==NULL)return;

        inorder(root->left);
        if(prev&&prev->val>root->val){
            if(!first){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        
        prev=new TreeNode(INT_MIN);
        first=middle=last=NULL;
        inorder(root);
        if(first && last)swap(first->val,last->val);
        else if(first && middle)swap(first->val,middle->val);

        
    }

};
