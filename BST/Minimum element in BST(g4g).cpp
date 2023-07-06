https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
int minValue(Node* root) {
    if(root==NULL)return -1;
    int mini = root->data;
    while(root->left){
        mini=root->left->data;
        root=root->left;
    }
    return mini;
    
}
