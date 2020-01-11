// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
//
// Example 1:
//
//
// Input: "1 + 1"
// Output: 2
//
//
// Example 2:
//
//
// Input: " 2-1 + 2 "
// Output: 3
//
// Example 3:
//
//
// Input: "(1+(4+5+2)-3)+(6+8)"
// Output: 23
// Note:
//
//
// 	You may assume that the given expression is always valid.
// 	Do not use the eval built-in library function.
//
//


//shunting-yard algorithm
class Solution {
public:
    stack<char> chars;
    stack<int> nums;
    unordered_map<char, int> op;
    int cal(int a, int b, char ch){
        if(ch == '+'){
            return a + b;
        }else if(ch == '*'){
            return a * b;
        }else if(ch == '-'){
            return b - a;
        }else
            return b / a;
    }
    int calculate(string str) {
        op['+'] = op['-'] = 1;
        op['*'] = op['/'] = 2;
        string s = "";
        for(auto ch:str){
            if(ch != ' ')
                s += ch;
        }
        for(int i = 0; i < s.length();){
            if(s[i] == ' ')
                continue;
            if((s[i] >= '0' && s[i] <= '9') || (i == 0 && s[i] == '-') || (s[i] == '-' && s[i - 1] == '-')){
//                nums.push(s[i] - '0');
                string s1;
                int f = 1;
                if(s[i] == '-'){
                    f = -1;
                    ++i;
                }
                while(s[i] >= '0' && s[i] <= '9') s1 += s[i++];
                nums.push(f*stoi(s1));
            }else{
                if(chars.empty() || s[i] == '(' || chars.top() == '(' || (s[i] != ')' && op[s[i]] > op[chars.top()])){
                    if(s[i] == ')' && chars.top() == '(') chars.pop();
                    else chars.push(s[i]);
                }else if(s[i] == ')'){
                    auto c = chars.top();
                    while(c != '('){
                        auto a = nums.top();
                        nums.pop();
                        auto b = nums.top();
                        nums.pop();
                        chars.pop();
                        nums.push(cal(a,b,c));
                        c = chars.top();
                    }
                    chars.pop();
                }else{
                    auto a = nums.top();
                    nums.pop();
                    auto b = nums.top();
                    nums.pop();
                    auto c = chars.top();
                    chars.pop();
                    nums.push(cal(a,b,c));
                    chars.push(s[i]);
                }
                ++ i;
            }
        }
        while(!chars.empty()){
            auto c = chars.top();
            chars.pop();
            auto a = nums.top();
            nums.pop();
            auto b = nums.top();
            nums.pop();
            nums.push(cal(a,b,c));
        }
        return nums.top();
    }
};
