// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
//
// Example 1:
//
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
//
//
//
// Note:
// In the string, each word is separated by single space and there will not be any extra space in the string.
//


class Solution {
private:

public:
    string reverseWords(string s) {
        string re;
        stack<char> stk;
        for(char ch: s){
            if(ch != ' ')
                stk.push(ch);
            else{
                while(!stk.empty()){
                    re += stk.top();
                    stk.pop();
                }
                re += ch;
            }
        }
        while(!stk.empty()){
                    re += stk.top();
                    stk.pop();
                }
        return re;
    }
};
