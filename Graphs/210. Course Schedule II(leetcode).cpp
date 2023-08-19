https://leetcode.com/problems/course-schedule-ii/description/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>in(numCourses);
        vector<int>ans;
        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a),in[a]++;

        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0)q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            ans.push_back(cur);
            q.pop();
            for(auto child:adj[cur]){
                in[child]--;
                if(in[child]==0)q.push(child);
            }
        }
        if(ans.size()==numCourses)return ans;
        else return {};
    }       
    
};
