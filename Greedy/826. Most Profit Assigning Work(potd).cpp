class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int>hash;
        for(int i =0;i<difficulty.size();i++){
            hash[difficulty[i]]= max(hash[difficulty[i]],profit[i]);
        }
        sort(worker.begin(),worker.end());
        int res=0;
        int maxi = 0;
        auto it = hash.begin();
        for(int i =0;i<worker.size();i++){
            while(it!=hash.end()&&worker[i]>=(*it).first){
                maxi = max(maxi,(*it).second);
                it++;
            }
           
            res+=maxi;

        }
        return res;
        


    }
};

// sorted difficulty wrt their profit value
// 2  4  6  8  10
// 10 20 30 40 50
// 4  5.  6. 7
