// global minima is when left >x and right>x as elements are unique and a base case of 1 element we should use >= signs
// in right rotated array right element idx = (i+1)%n  
// left element idx = (n+i-1)%n
//whatever be the graph , it can follow zig-zag or any patter but one property you should notice , that is 
// a right rotated array is forment by 1 by one taking rightmost element to array front, that means taking greatest elements one by one
// e.g 1 2 3 4 5 6 7  --- fist element to go will be 7 then 6 then 5 
// therefore we observe pattern in a graph that-->
// 1. if element is greater than rightmost element it belongs to the section of array that is due to rotation and cause disturbance to sorted nature
// therefore minima to the right s = mid+1
// 2. if element is less than right than it belongs to the section of array that was from original array and sorted , therefore minima to the left e = mid-1

int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    
    int s = 0;
    int e = A.size()-1;
    
    int mid = s+ ((e-s)>>2);
  
    
    while(s<=e){
        mid = s+ ((e-s)>>2);
        if(A[mid]<=A[(mid+1)%n]&&A[mid]<=A[(n+mid-1)%n])return A[mid];
        else if(A[mid]<A[n-1])e= mid-1;
        else s = mid+1;
        
        
    }
    return -1;
}
