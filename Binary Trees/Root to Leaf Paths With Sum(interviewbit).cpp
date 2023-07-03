/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
void solve(TreeNode*root,int sum,int k,vector<int>&temp,vector<vector<int>>&ans){
    if(root==NULL)return;
    else temp.push_back(root->val);
    sum+=root->val;
    if(sum==k&&!root->left&&!root->right)ans.push_back(temp);
    solve(root->left,sum,k,temp,ans);
    solve(root->right,sum,k,temp,ans);
    temp.pop_back();
    return;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>>ans;
    vector<int>temp;
    solve(A,0,B,temp,ans);
    return ans;
}
