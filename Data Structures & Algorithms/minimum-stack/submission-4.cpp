class MinStack {
    private:
        stack<int> st;
        stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min.empty()){
            min.push(val);
        }
        else {
            if(val<min.top()) min.push(val);
            else min.push(min.top());
        }
    }
    
    void pop() {
        if(!st.empty())
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto m = min.top();
        return m;
    }
};
