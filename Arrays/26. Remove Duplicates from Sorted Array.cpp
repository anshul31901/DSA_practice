//Algo 1 like linked list

//initialize i=0 
//when arr[i]=arr[i+1] initialize j=i+1 and increase till arr[j]!=arr[j+1]
//now j will be at last repetition (1 2 2 3 : i at 1 and j at last 2) so delete from i to j (j exclusive) by arr.erase(i,j);
//note: as i+1 se check krna h  last index pe scene pdta h to usme -1 ya kuch push kr dena aur last me remove   dena
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
//1st unique elements hi check honge so till arr[i]!=arr[j] increment j
//when (arr[i]!=arr[j]) increment i and put its value to arr[j]
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
