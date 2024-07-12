class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string res;
        for(int i =0;i<s.size();i++){

            if(s[i]=='*'&&!st.empty()&&st.top()!='*'){
                st.pop();
            
            }else st.push(s[i]);
            
            
        }

        while(!st.empty()){
           res.push_back(st.top());
           st.pop(); 
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
