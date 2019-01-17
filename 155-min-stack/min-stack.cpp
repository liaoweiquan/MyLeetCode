//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
//


class MinStack {
private:
    vector<int> stk;
    vector<int> minx;
    int nmin;
    int stkp;
public:
    /** initialize your data structure here. */
    MinStack() {
        stk = vector<int>(100,0);
        minx = vector<int>(100,0);
        stkp = -1; // point to the top item
    }
    
    void push(int x) {
        if(stkp + 1 >= stk.size()){
            stk.push_back(x);
            minx.push_back(0);
            ++ stkp;
        }
        else{
            stk[++stkp] = x;
        }
        
        if(stkp == 0){
            minx[0] = stk[0];
        }
        else{
            minx[stkp] = x < minx[stkp - 1] ? x : minx[stkp - 1];
        }
    }
    
    void pop() {
        -- stkp;
    }
    
    int top() {
        return stk[stkp];
    }
    
    int getMin() {
        return minx[stkp];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
