https://leetcode.com/problems/gas-station/submissions/1391988612/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        //is the solution possible?
        int gasgain= accumulate(gas.begin(),gas.end(),0);
        int gascost =accumulate(cost.begin(),cost.end(),0);

        //if cost is more there can't be a possible solution
        if(gascost>gasgain)return -1;

        int ans = 0;

        int sum = 0;

        //since there is a unique solution and it exists

        //once sum gets negative means that till now we haven't found the soloution so possible solution could be i+1;
        //at last the ans ptr is the resultant solution
        //: starting from ans till end sum doesn;t go negative.
        // and we know solution is unique and exists so this is the only case where we can make round trip and compensate all negatives.

        for(int i =0;i<cost.size();i++){
            sum+= gas[i]-cost[i];

            if(sum<0){
                sum = 0;
                ans = i+1;    
            }
        }
        return ans;


        
        

        
    }
};



// 1 2 3 4 5
// 3 4 5 1 2

// 4 2 0 3 3
