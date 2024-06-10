//approach1 =converting 1d index into 2 d and apply binary search
// let n = total columns  i be linear idx    row = i/n , col = row%n

// TC  = O(m*n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        int e = m*n-1;
        

        while(s<=e){
            int mid = s + ((e-s)>>1);
            if(matrix[mid/n][mid%n]==target)return true;
            else if(matrix[mid/n][mid%n]>target)e = mid-1;
            else s = mid+1;

        }
        return false;
        
    }
};
//best method
// approach 2 = apply binary search to find row first and then apply binary search on that row
// TC = O(log(num N+logM))  because first bs on rows and then one bs on desired row

class Solution {
public:
    bool bin_sr(vector<int>&v,int &k){
        int s = 0;
        int e = v.size()-1;
        int mid = s+((e-s)>>1);

        while(s<=e){
            mid = s+((e-s)>>1);
            if(v[mid]==k)return true;
            else if(v[mid]>k){
                e = mid-1;
            }
            else s = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size()-1;

        int s = 0;
        int e = n-1;
        int mid = s+((e-s)>>1);

        while(s<=e){
            mid = s+((e-s)>>1);
            if(matrix[mid][m]==target)return true;
            else if(matrix[mid][m]<target){
                s = mid+1;
            }
            else{

                if(matrix[mid][0]<=target){
                    return bin_sr(matrix[mid],target);
                }
                else e=mid-1;
               
            }
        }
        return false;



        
    }
};
