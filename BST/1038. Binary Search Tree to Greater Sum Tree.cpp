class Solution {
public:
    void solve(TreeNode* root,int&y){
        if(root==NULL)return;
        solve(root->right,y);
        root->val+=y;
        y=root->val;
        solve(root->left,y);
       
         
    }
    TreeNode* bstToGst(TreeNode* root) {
        int accsum=0;
        solve(root,accsum);
        return root;
    }
};
