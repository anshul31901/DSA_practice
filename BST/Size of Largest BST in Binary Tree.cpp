https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103?leftPanelTab=1
#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
//we create a constructor class to ease the navigation
    class NodeValue{
        public :
        int minNode;
        int maxNode;
        int size;

        NodeValue(int minNode,int maxNode,int size){
            this->minNode=minNode;
            this->maxNode=maxNode;
            this->size=size;

        }
    };
//this is a helper function and we use postorder traversal as it is suitable for bootom up approach
 NodeValue solve(TreeNode<int>* root){
   //considering a null root as a root with size 0 and a bst
     if(!root){
         return NodeValue(INT_MAX,INT_MIN,0);
     }
     auto left = solve(root->left);
     auto right= solve(root->right);
  //if the given node is grater that lefts maximun and lessrr than rights minimum value the tree is a bst and its size is (1+leftsize+right.size)
     if(root->data<right.minNode&&root->data>left.maxNode){
         return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),1+left.size+right.size);
//else we know that in bottom up approach the inclusion of this subtree will decline the condition of bst so we return non favourable values
//and the size is the max of both left and right subtrees
     }
     else return NodeValue(INT_MIN,INT_MAX,max(left.size,right.size));
 }

int largestBST(TreeNode<int>* root) 
{
    return solve(root).size;
}
