// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
//
// Example 2:
//
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
//


class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return 0;
    stack<int>stk;
    for(int i = 0;i <= s.size() - 1; ++i){
        if(s[i] == '(') stk.push(i);
        else if(s[i] == ')' && !stk.empty() && s[stk.top()] == '(') stk.pop();
        else stk.push(i);
    }

    if(stk.empty()) return s.size();
    else{
        int l = s.size(), t = 0;
        int maxn = 0;
        while(!stk.empty()){
            t = stk.top();
            stk.pop();
            maxn = max(maxn, l - t - 1);
            l = t;
        }
        maxn = max(maxn, l);
        return maxn;
    }
    }
};
