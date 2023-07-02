https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool path(TreeNode* root, int B,vector<int>&ans){
    if(root==NULL)return false;
    else ans.push_back(root->val);
    
    if(root->val==B)return true;
    
    if(path(root->left,B,ans)||path(root->right,B,ans))return true;
    else{
        ans.pop_back();
        return false;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    path(A,B,ans);
    return ans;
    
    
}
