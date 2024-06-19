class Solution {
public:
    int trap(vector<int>& height) {
        int left =0;
        int n = height.size();
        vector<int>maxLeft(n);
        vector<int>maxRight(n);
        int right=0;
        
        for(int i =0;i<n;i++){
            maxLeft[i]=left;
            maxRight[n-1-i]=right;
            right = max(right,height[n-1-i]);
            left = max(left,height[i]);
        }
        int trapped = 0;
        for(int i =0;i<n;i++){
            int t = min(maxLeft[i],maxRight[i]);
            if(height[i]<t){
                trapped += t-height[i];
            }

        }
        return trapped;
        
    }
};

// 0 0 1 1 2 2 2 2 3 3 3 3 left
// 3 3 3 3 3 3 3 2 2 2 1 0 right

// 0 1 0 2 1 0 1 3 2 1 2 1 array

// 0 0 1 0 1 1 1 0 0 1 1 0 trapwater thug shaker
