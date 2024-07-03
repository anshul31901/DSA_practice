//we know that 0 th element will lie in pos 0 to k , therefore 1st k +1 elements 
//min of k +1 elements on every step
//create a min Heap keep pushing elements in it
// if size>k pop element and include in array 

//instead of nlogn complexity we get n log k complexity
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        
        priority_queue<int,vector<int>,greater<int>>minH;
        vector<int>res;
        
        for(int i = 0 ;i<num;i++){
            minH.push(arr[i]);
            if(minH.size()>K){
                res.push_back(minH.top());
                minH.pop();
            }
            
            
        }
        while(!minH.empty()){
            res.push_back(minH.top());
            minH.pop();
        }
        return res;
    }
};
