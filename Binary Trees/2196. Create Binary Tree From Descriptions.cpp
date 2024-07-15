/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>mp;
        map<int,int>prnt;

        for(auto i :descriptions){
            int parent = i[0];
            int child = i[1];
            int left = i[2];
            

            if(mp.find(parent)==mp.end()){
                TreeNode* p = new TreeNode(parent);
                mp[parent]= p;
            }
            if(mp.find(child)==mp.end()){
                TreeNode* p = new TreeNode(child);
                mp[child]= p;
            }
            if(left){
                mp[parent]->left = mp[child];
                
                
            }
            else mp[parent]->right = mp[child];
            prnt[child]=parent;

        }
        auto it = (*prnt.begin()).first;
        while(true){
            if(prnt[it]==0){
                return mp[it];
            }
            else it = prnt[it];
        }

        
    }
};
