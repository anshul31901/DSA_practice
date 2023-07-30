https://leetcode.com/problems/sudoku-solver/submissions/
class Solution {
public:
    bool canPlace(int row,int col,char c,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col]==c)return false;
            if(board[row][i]==c)return false;
            if(board[(row/3)*3+(i/3)][(col/3)*3+(i%3)]==c)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(canPlace(i,j,c,board)==true){
                            board[i][j]=c;
                            if(solve(board))return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
                
            }
           
        }
        return true;
    }
