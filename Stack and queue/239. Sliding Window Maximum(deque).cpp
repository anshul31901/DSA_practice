class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int>q;

       int i =0,j =0;

       vector<int>res;

       // we assume a deque ds where for a sliding window we store its max element at front
// as if we move window forward nums[j] could potentially be max element for k windows
//but now it is sure that elements in the dq less than nums[j] cant become max elements for windows beyond so we remove that
// also when incrementing i we check if its q.front means if its max element for that window and we are sliding it it ownt be there for next window so we pop from front

       for(j =0;j<nums.size();j++){
            while(!q.empty()&&q.back()<nums[j]){
                q.pop_back();
            }


            q.push_back(nums[j]);
            while(j-i+1>k){
                if(nums[i]==q.front())q.pop_front();

                i++;
            }


            if(j-i+1==k){
                res.push_back(q.front());
            }
       }
       return res;


        
    }
};
