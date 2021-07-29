class MinStack {
    
public:
    stack<int>s;
    stack<int>min_s;
    
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (!min_s.empty() && min_s.top() < x)
            min_s.push(min_s.top());
        else
            min_s.push(x);
    }
    
    void pop() {
        if (!s.empty()) {
            s.pop();
            min_s.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */