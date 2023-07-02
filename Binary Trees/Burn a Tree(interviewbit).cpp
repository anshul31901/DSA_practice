https://www.interviewbit.com/problems/burn-a-tree/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A, int B) {
        map<TreeNode*,TreeNode*>m;
        TreeNode*target=NULL;
        queue<TreeNode*>q;
        q.push(A);
        while(!q.empty()){
            TreeNode*temp = q.front();
            q.pop();
            if(temp->val==B)target = temp;
            if(temp->left){
                m[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                m[temp->right]=temp;
                q.push(temp->right);
            }
        }

            int ans=0;
            map<TreeNode*,bool>visited;
            queue<pair<TreeNode*,int>>q1;
            q1.push({target,0});
           
            while(!q1.empty()){
                auto temp = q1.front().first;
                int dist = q1.front().second;
                visited[temp]=true;
                q1.pop();

                if(m[temp]&&!visited[m[temp]]){
                    q1.push({m[temp],dist+1});
                    
                }
                if(temp->left&&!visited[temp->left]){
                    q1.push({temp->left,dist+1});
                    
                }
                if(temp->right&&!visited[temp->right]){
                    q1.push({temp->right,dist+1});
                   
                }
                ans=max(ans,dist);
            }
            return ans; 
}
