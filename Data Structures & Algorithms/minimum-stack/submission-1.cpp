class MinStack {
public:
    stack<int>st,s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(st.empty()||st.top()>=val)
        {
            st.push(val);
        }            
    }
    
    void pop() {
        if((!st.empty())&&st.top()==s.top())
        {
            st.pop();
        }
        s.pop();
    }
    
    int top() {
        if(!s.empty())return s.top();
        return -1;
    }
    
    int getMin() {
        if(!st.empty())return st.top();
        return -1;
    }
};
