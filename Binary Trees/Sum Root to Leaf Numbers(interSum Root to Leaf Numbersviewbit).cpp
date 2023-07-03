https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode* root,int n){
    if(root==NULL)return 0;
    if(!root->left&&!root->right){
        return (n*10+root->val)%1003;
        
    }
    int num = (n*10+root->val)%1003;
    return (solve(root->left,num)+solve(root->right,num))%1003;
    
    
}
int Solution::sumNumbers(TreeNode* A) {
    return solve(A,0);
}
