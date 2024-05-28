class Solution {
public:
    double myPow(double x, int n) {
        double base = x;
        double ans =1;
        int sign = n<0?-1:1;
        n = abs(n);
        while(n>0){
            if(n&1==1)ans*=base;

            base*=base;
            n=n>>1;
        }
        if(sign<0)ans=1/ans;
        return ans;
        
    }
};

