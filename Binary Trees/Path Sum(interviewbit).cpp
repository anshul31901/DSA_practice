https://www.interviewbit.com/problems/path-sum/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode*root,int cur,int sum){
    if(root==NULL)return 0;
    if(root->val+cur==sum&&!root->left&&!root->right)return 1;
   
    
        cur+=root->val;
        return solve(root->left,cur,sum)||solve(root->right,cur,sum);
    
    
}
int Solution::hasPathSum(TreeNode* A, int B) {
    
    return solve(A,0,B);
}
