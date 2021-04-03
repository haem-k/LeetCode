//M1) 92ms, 16.3MB
class MinStack1 {
private:
    vector<int> min_stack;
    
public:
    /** initialize your data structure here. */
    
    MinStack() {
    }
    
    void push(int val) {
        min_stack.push_back(val);
    }
    
    void pop() {
        min_stack.pop_back();
    }
    
    int top() {
        return min_stack.back();
    }
    
    // get minimum element in constant time
    int getMin() {
        return *min_element(min_stack.begin(), min_stack.end());
    }
    
};


// M2) 24ms, 16.3MB
class MinStack2 {
private:
    stack<pair<int, int>> min_stack;
    
public:
    /** initialize your data structure here. */
    
    MinStack() {
    }
    
    void push(int val) {
        if(min_stack.empty())
            min_stack.push({val, val});
        else
            min_stack.push({val, min(val, min_stack.top().second)});
    }
    
    void pop() {
        min_stack.pop();
    }
    
    int top() {
        return min_stack.top().first;
    }
    
    // get minimum element in constant time
    int getMin() {
        return min_stack.top().second;
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