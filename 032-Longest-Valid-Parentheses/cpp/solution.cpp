/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <stack>

using namespace std;

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
int main(){
	Solution solution;
	string s = ")()())";
	int res = solution.longestValidParentheses(s);
	cout << res << endl;
	return 0;
}