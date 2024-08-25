//brute force approach: search for all persons and if 
    // matrix[person][i] =0 && matrix[i][person] holds true for every i except of when i = person that person is celebrity.
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
       
        
       
       
        
        for(int i =0;i<n;i++){
            bool flag = true;
            for(int j = 0 ;j<n;j++){
                
                if(mat[i][j]==0&&(mat[j][i]==1||i==j)){
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
                
                
                
            }
            if(flag)return i;
        }
        return -1;
    }
};

there can be only one celebrity as if there are two of them one will not know the other one and that does not 
align with the condition of known by all 




