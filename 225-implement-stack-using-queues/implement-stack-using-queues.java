// Implement the following operations of a stack using queues.
//
//
// 	push(x) -- Push element x onto stack.
// 	pop() -- Removes the element on top of the stack.
// 	top() -- Get the top element.
// 	empty() -- Return whether the stack is empty.
//
//
// Example:
//
//
// MyStack stack = new MyStack();
//
// stack.push(1);
// stack.push(2);  
// stack.top();   // returns 2
// stack.pop();   // returns 2
// stack.empty(); // returns false
//
// Notes:
//
//
// 	You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// 	Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// 	You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
//
//


import java.util.ArrayList;

/*
 * @lc app=leetcode id=225 lang=java
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (37.35%)
 * Total Accepted:    115.3K
 * Total Submissions: 308.8K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * 
 * 
 * Example:
 * 
 * 
 * MyStack stack = new MyStack();
 * 
 * stack.push(1);
 * stack.push(2);  
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 * 
 * 
 */
class MyStack {

    /** Initialize your data structure here. */
    public int ptr;
    public ArrayList<Integer> list;
    public MyStack() {
        list = new ArrayList<Integer>(1000);
        ptr = -1;
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(ptr == -1){
            if(list.isEmpty()){
                ++ ptr;
                list.add(ptr,Integer.valueOf(x));
            }
            else{
                ++ptr;
                list.set(ptr, Integer.valueOf(x));
            }
        }else{
            if(ptr + 1 >= list.size()){
                ptr ++;
                list.add(ptr, Integer.valueOf(x));
            }else{
                list.set(++ptr, Integer.valueOf(x));
            }
        }

    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        return (int)list.get(ptr--);
    }
    
    /** Get the top element. */
    public int top() {
        return (int)list.get(ptr);
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return ptr == -1;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */

