
int Solution::isValid(string A) {
    stack<char>st;
    
    for(int i =0;i<A.size();i++){

        if(A[i]==')'){
            if(st.empty())return 0;
            else if(st.top()=='(')st.pop();
            else return 0;
        }
        else if(A[i]==']'){
            if(st.empty())return 0;
            else if(st.top()=='[')st.pop();
            else return 0;
        }
        else if(A[i]=='}'){
            if(st.empty())return 0;
            else if(st.top()=='{')st.pop();
            else return 0;
        }  
        else st.push(A[i]);      
    }
    
    return st.empty();
}
