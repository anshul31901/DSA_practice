class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //maxHeap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;

        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto p :mp){
            heap.push({p.second,p.first});

            if(heap.size()>k)heap.pop();
        }
        vector<int>res;
        while(!heap.empty()){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }

};
