Editorial for this problem :https://leetcode.com/problems/sum-of-square-numbers/editorial/?envType=daily-question&envId=2024-06-17#solution
contains all methods and theories


key points learned:
1. some of 1st n odd numbers = n*n


//method 1 : sqrt usinng inbuilt function
#include<bits/stdc++.h>
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long  a = 0;a*a<=c;a++){
            double b = c-a*a;
            b = sqrt(b);
            if((int)b == b)return true;

        
        }
        return false;
           
    }
};

//method 2 : square root using binary search-- use this instead use of sqrt
    bool binary_search(int b,long s,long e){

        long mid = s+(e-s)/2;

        while(s<=e){
            mid = s+(e-s)/2;

            if(mid*mid==b)return true;
            else if(mid*mid>b)e=mid-1;
            else s =mid+1;
        }
        return false;

    }

