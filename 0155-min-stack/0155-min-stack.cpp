class MinStack {
public:
    stack<int>mainstack;
    stack<int>auxistack;
    MinStack() {
        auxistack.push(INT_MAX);
    }
    void push(int val) {
        mainstack.push(val);
        auxistack.push(min(val,auxistack.top()));
    }
    
    void pop() {
        if(!mainstack.empty()){
            mainstack.pop();
        }
        if(!auxistack.empty()){
            auxistack.pop();
        }
    }
    
    int top() {
        if(!mainstack.empty()){
            return mainstack.top();
        }
        return 0;
    }
    
    int getMin() {
        if(!auxistack.empty()){
            return auxistack.top();
        }
        return INT_MAX;
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