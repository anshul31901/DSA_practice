//Algo 1 like linked list
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        nums.push_back(101);
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                for(int j = i+1;j<nums.size()-1;j++){
                    if(nums[j]!=nums[j+1]){
                        nums.erase(nums.begin()+i,nums.begin()+j);
                        break;
                    }
                }
            }
        }
        nums.erase((nums.end()-1));
        return nums.size();
        
    }
  
};
//Algo 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }

        }
        return i+1;

        
    }
 
};
