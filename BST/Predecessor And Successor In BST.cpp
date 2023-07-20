https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void successor(BinaryTreeNode<int>* root, int key,pair<int,int>&ans){
    if(root==NULL)return;
    if(root->data>key){
        ans.second=root->data;
        successor(root->left,key,ans);
    }
    else successor(root->right,key,ans);
    
}
void predecessor(BinaryTreeNode<int>* root, int key,pair<int,int>&ans){
    if(root==NULL)return;
    if(root->data<key){
        ans.first=root->data;
        predecessor(root->right,key,ans);
    }
    else predecessor(root->left,key,ans);


}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{   
    pair<int,int>ans={-1,-1};
    predecessor(root,key,ans);
    successor(root,key,ans);
    return ans;

    // Write your code here.

}
