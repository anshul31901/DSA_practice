https://www.codingninjas.com/studio/problems/childrensumproperty_790723?leftPanelTab=0

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root==NULL)return;
    int childsum=0;
    if(root->left)childsum+=root->left->data;
    if(root->right)childsum+=root->right->data;
    if(childsum<root->data){
    if(root->left)root->left->data=root->data;
    if(root->right)root->right->data=root->data;        
    }
    if(root->left)changeTree(root->left);
    if(root->right)changeTree(root->right);

    int val=0;
    if(root->left)val+=root->left->data;
    if(root->right)val+=root->right->data;

    if(root->left || root->right)root->data=val;
}  
