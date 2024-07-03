stack<int>st;
stack<int>m_st;
int mini = INT_MAX;
MinStack::MinStack() {
    st = stack<int>();
    m_st = stack<int>();
    
}


void MinStack::push(int x) {
    st.push(x);
    if(m_st.empty()){
        mini = x;
        m_st.push(mini);
    }
    else{
        mini = min(x,mini);
        m_st.push(mini);
    }
    
}

void MinStack::pop() {
    if(st.empty()) return;
    
    st.pop();
    m_st.pop();
    if(!m_st.empty())mini = m_st.top();
    
    
}

int MinStack::top() {
    if(!st.empty())return st.top();
    
    return -1;
}

int MinStack::getMin() {
    if(st.empty())return -1;
    
    return m_st.top();
    

    
    
}
