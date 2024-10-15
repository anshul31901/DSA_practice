class Solution {
public:
    long long minimumSteps(string t) {

        //we traverse using 2 ptr approach
        //if left is on black and right is on white we swap them using (end-start) swaps


        int s = 0;
        int n = t.size()-1;
        int e = n;
        long long swaps = 0;

        while(s<e){


            while(s<=n&&t[s]=='0'){
                s++;
            }
            while(e>=0&&t[e]=='1'){
                e--;
            }  
            if(s<e){
                swaps += (e-s);
                s++;
                e--;
            }           
        }
        return swaps;
        
    }
};

