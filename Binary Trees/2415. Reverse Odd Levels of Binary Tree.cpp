https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/submissions/1407367560/

class Solution {
public:
//we call dfs on first 2 child nodes, since level is 1(odd) we swap those
// we follow the algo that 
//if level is odd we swap both node values
// and call dfs

    void dfs(TreeNode* node1, TreeNode* node2, bool isodd){
        if(node1==NULL||node2==NULL){
            return ;
        }

        if(isodd){
            int temp = node2->val;
            //swap for odd levels
            node2->val = node1->val;
            node1->val = temp;
        }

        dfs(node1->left,node2->right,!isodd);
        dfs(node1->right,node2->left,!isodd);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {


        //dfs contains possible swappable pairs that should be swapped if level is odd
        //eg 1234   (1,4)(2,3)
        //and a variable that indicates if we should swap-odd->then swap, even -> then don't
        dfs(root->left,root->right,true);
        return root;

        
    }
};
