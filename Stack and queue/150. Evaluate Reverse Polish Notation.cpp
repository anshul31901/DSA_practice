//try to compare just first value like tokens[0] to avoid string conversion;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string>st;

        for(auto s:tokens){
            if(s=="+"||s=="/"||s=="-"||s=="*"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();

                if(s=="+")st.push(to_string(a+b));
                else if(s=="-")st.push(to_string(b-a));
                else if(s=="*")st.push(to_string(a*b));
                else st.push(to_string(b/a));
            }
            else st.push(s);

    
        }
        return stoi(st.top());
        
    }
};
