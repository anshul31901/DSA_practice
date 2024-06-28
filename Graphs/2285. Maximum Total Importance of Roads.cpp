// the node having maximum number of edges will get max number and so forth second max for second most no of edges and all
//on observation we find out that we dont actually need the nodes with max edges we just need the frequency of the nodes
#define ll long long int
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        long long ans =0;
        vector<int>freq(n,0);

        for(auto edge:roads){
            freq[edge[0]]++;
            freq[edge[1]]++;
        }
        sort(freq.begin(),freq.end());
        int x = 1;
        for(int i =0;i<n;i++){
            ans+= 1ll*freq[i]*x;
            x++;
        }
        return ans;
        
    }
};
