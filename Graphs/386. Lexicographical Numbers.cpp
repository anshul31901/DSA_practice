class Solution {
public:

    void dfs(int i , vector<int>&res,int n ){
        res.push_back(i);

        for(int j =0;j<=9;j++){
           
            int x = 10*i+j;
            if(x<=n){
                dfs(x,res,n);
            }
            else return ;
        }

    }
    vector<int> lexicalOrder(int n) {
        vector<int>res;

        for(int i =1 ;i<=9;i++){
            if(i<=n){
                dfs(i,res,n);
            }
        }
        
        return res;
    }

};
