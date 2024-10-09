
class Solution {
public:
    int minAddToMakeValid(string s) {

        int n = s.size();
        int ct=0;

        stack<char>st;

        for(int i =0;i<n;i++){
            
            if(s[i]==')'){
                if(!st.empty()){
                    st.pop();
                }
                else ct++;
                //if any ( are present they are present after this ) and cannot close it
            }
            else st.push('(');


        }
        return st.size()+ct;

        //space optimisation create counter for no. of '(' instead of stack.        
    }
};
