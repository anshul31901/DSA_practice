https://leetcode.com/problems/n-queens/submissions/
class Solution {
  

  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n,vector<int>&left,vector<int>&left1,vector<int>&left2) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (left[row]==0&&left1[row+col]==0&&left2[n-1+col-row]==0) {
          board[row][col] = 'Q';
          left[row]=1;
          left1[row+col]=1;
          left2[n-1+col-row]=1;
          solve(col + 1, board, ans, n,left,left1,left2);
          //backtracking
          board[row][col] = '.';
          left[row]=0;
          left1[row+col]=0;
          left2[n-1+col-row]=0;         
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      //<-- direction hash array
      vector<int>left(n,0);
      //left down direction
      vector<int>left1(2*n-1,0);
      //left up direction
      vector<int>left2(2*n-1,0);
      solve(0, board, ans, n,left,left1,left2);
      return ans;
    }
};
