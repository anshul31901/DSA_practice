// out of l and r which one is smaller we move that and update max corresponding to the smaller

// if me move left we calcuate water at left and its bounded by maxLeft to it 
//way to prove it is 
//Every value maxL ever takes was set on some step where height[right] (at that time) was >= height[left] (at that time). So each new maxL has a "receipt" — a right-side bar that was big enough to justify it.

//and vice versa ; O(n) TC and O(1) space.
class Solution {
public:

    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0 ;
        int r = n-1;

        int maxL = 0;
        int maxR = 0 ;
        int trapWater = 0 ;

        while(l<r){

            if(height[l]<=height[r]){
                maxL = max(maxL,height[l]);
                trapWater += maxL-height[l];
                l++;
            }
            else{
                maxR = max(maxR,height[r]);
                trapWater += maxR- height[r];
                r--;
            }
        }
        return trapWater;
     
    }
};
class Solution {
public:

    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0 ;
        int r = n-1;

        int maxL = 0;
        int maxR = 0 ;
        int trapWater = 0 ;

        while(l<r){

            if(height[l]<=height[r]){
                maxL = max(maxL,height[l]);
                trapWater += maxL-height[l];
                l++;
            }
            else{
                maxR = max(maxR,height[r]);
                trapWater += maxR- height[r];
                r--;
            }
        }
        return trapWater;
     
    }
};
