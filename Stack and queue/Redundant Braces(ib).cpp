int Solution::braces(string A) {
    
    stack<char>st;
    for(int i =0;i<A.size();i++){
        if(A[i]=='('||A[i]=='*'||A[i]=='+'||A[i]=='-'||A[i]=='/')st.push(A[i]);
        else if(A[i]==')')
        {
            if(st.top()=='('){
                // means no expression to close
                return 1;
            }
            
            while(st.top()!='('){
                st.pop();
            }
            st.pop();
        }
    }
    return 0;
}
