class MinStack {
public:
    stack<int> mini;
    stack<int> stk;

    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        if(stk.size() == 1){
            mini.push(val);
        }
        else if(mini.top()>=val) mini.push(val);
        
    }
    
    void pop() {
        if(mini.top() == stk.top()) mini.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mini.top();
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