https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution{
    public:
    void solve(int row,int col,string &s, vector<string>&ans,vector<vector<int>>&visited,vector<vector<int>>&m,int n){
      //base case :- if we reach destination return the string value and pop back and mark unvisited  
      if(row==n-1&&col==n-1)
        {   
            ans.push_back(s);
            visited[n-1][n-1] = 0;
            s.pop_back();
            return;
        }
        //in alphabetic order DLRU
        if(row<n-1&& m[row+1][col]==1 && visited[row+1][col]==0){
            //down
            visited[row+1][col]=1;
            s=s+'D';
            solve(row+1,col,s,ans,visited,m,n);
            //  visited[row+1][col]=0;
            // s.pop_back();
            

        }
        
        if(col>0&&m[row][col-1]==1&&visited[row][col-1]==0){
            //left
            visited[row][col-1]=1;
            s=s+'L';
            solve(row,col-1,s,ans,visited,m,n);
            // visited[row][col-1]=0;                        
            // s.pop_back();


        }
        
        if(col<n-1&&m[row][col+1]==1&&visited[row][col+1]==0){
            //Alrighty aphrodite
            visited[row][col+1]=1;
            s=s+'R';
            solve(row,col+1,s,ans,visited,m,n);
            //             visited[row][col+1]=0;
            // s.pop_back();


        }
        
        if(row>0&&m[row-1][col]==1&&visited[row-1][col]==0){
            //UP
            visited[row-1][col]=1;
            s=s+'U';
            solve(row-1,col,s,ans,visited,m,n);
            //             visited[row-1][col]=0;
            // s.pop_back();

        }
      //when we have nowhere to go we will pop back the string and unvisit the matrix block
        visited[row][col]=0;                        
        s.pop_back();

    }
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>visited(n,vector<int>(n,0));
        if(m[0][0]==0){
            return {"-1"};
        }
        visited[0][0]=1;
        vector<string>ans;
        string s="";
        solve(0,0,s,ans,visited,m,n);
        return ans;
    }
};
    
