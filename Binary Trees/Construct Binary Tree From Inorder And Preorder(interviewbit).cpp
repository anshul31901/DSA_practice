https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    TreeNode* build(vector<int>& preorder,int pre_start,int pre_end, vector<int>& inorder,int in_start,int in_end,unordered_map<int,int>&m)
    {
        if(pre_start>pre_end||in_start>in_end)return NULL;
        if(pre_start<=pre_end||in_start<=in_end){
           int root_val= preorder[pre_start];
           int idx = m[root_val];
           int length_LST =idx-in_start; 
           TreeNode*root=new TreeNode(root_val);
           root->left=build(preorder,pre_start+1,pre_start+length_LST,inorder,in_start,idx-1,m);
           root->right = build(preorder,pre_start+length_LST+1,pre_end,inorder,idx+1,in_end,m);
           return root;
        }
        else return NULL;
      
        

    }
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
        if(B.size()==0)return NULL;
        unordered_map<int,int>m;
        for(int i=0;i<B.size();i++){
            m[B[i]]=i;
        }
            int n= A.size();
            TreeNode*root = build(A,0,n-1,B,0,n-1,m);
            return root;    
    
}
