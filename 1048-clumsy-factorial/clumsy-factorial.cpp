// Normally, the factorial of a positive integer n is the product of all positive integers less than or equal to n.  For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
//
// We instead make a clumsy factorial: using the integers in decreasing order, we swap out the multiply operations for a fixed rotation of operations: multiply (*), divide (/), add (+) and subtract (-) in this order.
//
// For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  However, these operations are still applied using the usual order of operations of arithmetic: we do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.
//
// Additionally, the division that we use is floor division such that 10 * 9 / 8 equals 11.  This guarantees the result is an integer.
//
// Implement the clumsy function as defined above: given an integer N, it returns the clumsy factorial of N.
//
//  
//
// Example 1:
//
//
// Input: 4
// Output: 7
// Explanation: 7 = 4 * 3 / 2 + 1
//
//
// Example 2:
//
//
// Input: 10
// Output: 12
// Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 10000
// 	-2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit within a 32-bit integer.)
//
//


class Solution {
public:
    int getPriority(char ch) {
        if (ch == '(') return 1;
        else if (ch == '+' || ch == '-') return 2;
        else if (ch == '*' || ch == '/') return 3;
        else return 4;
    }

    void calculate(stack<int> &mystack, char operation) {
        int num1, num2, num3;
        num2 = mystack.top();
        mystack.pop();
        num1 = mystack.top();
        mystack.pop();
        if (operation == '+') {
            num3 = num1 + num2;
        }
        else if (operation == '-') {
            num3 = num1 - num2;
        }
        else if (operation == '*') {
            num3 = num1 * num2;
        }
        else if (operation == '/') {
            num3 = num1 / num2;
        }

        mystack.push(num3);
    }

    int calculator(string str) {
        stack<int> mystack_number;
        stack<char> mystack_operation;
        int i = 0, j;
        int size = str.size();
        char tmp_operation;
        string tmp_num;
        while (i < size) {
            if (str[i] >= '0' && str[i] <= '9') {
                j = i;
                while (j < size && str[j] >= '0' && str[j] <= '9') { j++; }
                tmp_num = str.substr(i, j - i);
                mystack_number.push(atoi(tmp_num.c_str()));
                i = j;
            }
            else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
                if (mystack_operation.empty()) {
                    mystack_operation.push(str[i]);
                }
                else {
                    while (!mystack_operation.empty()) {
                        tmp_operation = mystack_operation.top();
                        if (getPriority(tmp_operation) >= getPriority(str[i])) {
                            //计算
                            calculate(mystack_number, tmp_operation);
                            mystack_operation.pop();
                        }
                        else break;
                    }
                    mystack_operation.push(str[i]);
                }
                i++;
            }
            else {
                if (str[i] == '(') mystack_operation.push(str[i]);
                else {
                    while (mystack_operation.top() != '(') {
                        tmp_operation = mystack_operation.top();

                        calculate(mystack_number, tmp_operation);
                        mystack_operation.pop();
                    }
                    mystack_operation.pop();
                }
                i++;
            }

        }

        while (!mystack_operation.empty()) {
            tmp_operation = mystack_operation.top();
            calculate(mystack_number, tmp_operation);
            mystack_operation.pop();
        }
        return mystack_number.top();
    }
    int clumsy(int N) {

        int cur = 0;
        vector<char> o;
        o.push_back('*');
        o.push_back('/');
        o.push_back('+');
        o.push_back('-');
        string str = "";
        for(int i = N; i >= 1; -- i){
            str += to_string(i);
            if(i > 1)
                str += o[cur];
            cur = (cur + 1) % 4;
        }
        return calculator(str);
    }
};
