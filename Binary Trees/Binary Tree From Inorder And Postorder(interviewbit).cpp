https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    TreeNode* build(vector<int>& postorder,int post_start,int post_end, vector<int>& inorder,int in_start,int in_end,unordered_map<int,int>&m)
    {
        if(post_start>post_end||in_start>in_end)return NULL;
        if(post_start<=post_end||in_start<=in_end){
           int root_val= postorder[post_end];
           int idx = m[root_val];
           int len_RST =in_end-idx; 
           TreeNode*root=new TreeNode(root_val);
            root->right=build(postorder,post_end-len_RST,post_end-1,inorder,idx+1,in_end,m);
            root->left = build(postorder,post_start,post_end-len_RST-1,inorder,in_start,idx-1,m);
           return root;
        }
        else return NULL;
      
        

    }
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
        if(B.size()==0)return NULL;
        unordered_map<int,int>m;
        for(int i=0;i<A.size();i++){
            m[A[i]]=i;
        }
            int n= A.size();
            TreeNode*root = build(B,0,n-1,A,0,n-1,m);
            return root;    
    
}
