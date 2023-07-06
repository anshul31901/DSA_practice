https://practice.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst

int floor(Node* root, int x) {
    // Code here
    if(root==NULL)return -1;
    int ans=-1;
    while(root){
        if(root->data==x)return x;
        else if(root->data<x){
            ans=root->data;
            root=root->right;
        }
        else root=root->left;
    }
    return ans;
}
