https://practice.geeksforgeeks.org/problems/children-sum-parent/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=hildren-sum-parent
/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(root==NULL)return 0;
        if(root->left==NULL&&root->right==NULL)return 1;
        if(root->left&&root->right)
        {
            if(root->data!=root->left->data+root->right->data)return 0;
            else return isSumProperty(root->left)&&isSumProperty(root->right);
        }
        if(root->left==NULL){
            if(root->data!=root->right->data)return false;
            else return isSumProperty(root->right);
        }
        else if(root->right==NULL){
            if(root->data!=root->left->data)return false;
            else return isSumProperty(root->left);            
        }
    }
};
