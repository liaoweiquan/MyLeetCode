// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
// Note:
//
//
// 	Division between two integers should truncate toward zero.
// 	The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
//
//
// Example 1:
//
//
// Input: ["2", "1", "+", "3", "*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
//
//
// Example 2:
//
//
// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
//
//
// Example 3:
//
//
// Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
// Output: 22
// Explanation: 
//   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
//
//


class Solution {
private:
    bool isDigits(string c){
        if(c.size() > 1)
            return true;
        if(c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0]== '/')
            return false;
        return true;
    }
    int cal(int a, int b, char c){
        if(c == '+')
            return a + b;
        if(c == '-')
            return a - b;
        if(c == '*')
            return a * b;
        if(c == '/')
            return a / b;
    }
    int str2int(string c){
        int res = 0;
        bool g = true;
        for(char ch: c){
            if(ch == '-')
                g = false;
            else
                res = 10 * res + ch - '0';
        }
        
        
        return g == true ? res : (-1) * res;
    }
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        //int res = 0;
        stack<int> stk;
        for(int i = 0; i < tokens.size(); ++i){
            if(isDigits(tokens[i])){
                int n = str2int(tokens[i]);
                stk.push(n);
            }
            else{
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(cal(a, b, tokens[i][0]));
            }
        }
        return stk.top();
    }
};
