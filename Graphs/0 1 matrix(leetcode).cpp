https://leetcode.com/problems/01-matrix/description/




// we maintain a smilar visited matrix with all elements initially unvisited;
//we make a queue<pair<int,int>> which stores co ordinates of the points of the mat matrix.
// initially we put all the zeroes in the queue mark them visited and as they are zeroes their dist must be 0 so its mat value remains unchanges.
//when we obtain a node<i,j> from queue we find  all its unvisited neighbours
// 1)update their value to be 1+mat[i][j]    (as mat[i][j] is obtained from queue so it must be visited and have correct updated value).
// 2)mark them visited and push them also inside queue. (so they do the same to their neighbours).

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
//pushing all the zeroes in the queue and making them visited and setting their dis =0
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
            if(mat[i][j]==0){
                vis[i][j]=1;
                q.push({i,j});
            }
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            int i = a.first;
            int j = a.second;
            //left cell
            if(j-1>=0&&vis[i][j-1]==0){
                mat[i][j-1]=1+mat[i][j];
                vis[i][j-1]=1;
                q.push({i,j-1});
            }
            //right cell
            if(j+1<m&&vis[i][j+1]==0){
                mat[i][j+1]=1+mat[i][j];
                vis[i][j+1]=1;
                q.push({i,j+1});
            }
           //up cell
            if(i-1>=0&&vis[i-1][j]==0){
                mat[i-1][j]=1+mat[i][j];
                vis[i-1][j]=1;
                q.push({i-1,j});
            }
            //down cell
            if(i+1<n&&vis[i+1][j]==0){
                mat[i+1][j]=1+mat[i][j];
                vis[i+1][j]=1;
                q.push({i+1,j});
            }
        }
        return mat;



    }
};
