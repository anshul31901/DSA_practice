https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ans=-1;
    while(root){
        if(root->data==input)return input;
        if(root->data>input){
            ans=root->data;
            root=root->left;
        }
        else root=root->right;
    }
    return ans;
}
