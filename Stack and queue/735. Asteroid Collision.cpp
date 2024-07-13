//O(n) sc O(n) for stack
//-><- me hi collission hoga 
//let x be the negative element if stack is empty tab push kro usko stack me  ya st.top bhi negative h
//nahi to tab tak cancel krte jao +ve st.top() and -ve x ko  if they both equal the both explode
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(int i =0;i<asteroids.size();i++){
            int x = asteroids[i];

            if(x<0){
                while(!st.empty()&&x<0&&st.top()>=0){
                    //non negative and negative ka sum 0 equal magnitude ke case me hi aaega 
                    int sum = st.top()+x;
                    if (sum >0){
                        x=0;
                        break;
                    }
                    else if(sum==0){
                        st.pop();
                        x=0;
                        break;
                    }
                    else st.pop();
                }
                if(x!=0)st.push(x);
            }
            else st.push(x);
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
