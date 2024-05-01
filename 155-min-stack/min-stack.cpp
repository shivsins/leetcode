// Hint: Store the min val till that level of stack

class MinStack {
    vector<vector<int>> vec;
    int t;
public:
    MinStack() {
        t = -1;
    }
    
    void push(int val) {
        if(t<0){
            vec.push_back({val,val});
        }else{
            vec.push_back({val,min(val,vec[t][1])});
        }
        t++;
    }
    
    void pop() {
        t--;
        vec.pop_back();
    }
    
    int top() {
        return vec[t][0];
    }
    
    int getMin() {
        return vec[t][1];
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