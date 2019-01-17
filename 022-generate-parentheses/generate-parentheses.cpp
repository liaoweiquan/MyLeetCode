//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
private:
    void get(vector<string>&v, string s,int open, int close, int max){
    if(s.size() == max*2){
        v.push_back(s);
        return;
    }
    if(open < max){
        get(v,s+'(',open+1, close, max);
    }
    if(close<open){
        get(v,s+')',open, close+1, max);
    }
}
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> v;
    if(n==0) return v;
    get(v,"",0,0,n);
    return v;
    }
};
