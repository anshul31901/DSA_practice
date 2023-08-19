https://leetcode.com/problems/course-schedule/description/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>in(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a),in[a]++;

        }
        int ct=0;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0)q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            ct++;
            for(auto child:adj[cur]){
                in[child]--;
                if(in[child]==0)q.push(child);
            }
        }
        return (ct==numCourses);
    }
};
