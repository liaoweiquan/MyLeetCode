/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
	    for(int i = 0;i < s.size(); ++i){
	        switch (s[i]){
	            case '(':
	                stk.push(s[i]);
	                break;
	            case '{':
	                stk.push(s[i]);
	                break;
	            case '[':
	                stk.push(s[i]);
	                break;
	            case ')':
	                if(stk.empty() || stk.top()!='(') return false;
	                else stk.pop();
	                break;
	            case '}':
	                if(stk.empty() || stk.top()!='{') return false;
	                else stk.pop();
	                break;
	            case ']':
	                if(stk.empty() || stk.top()!='[') return false;
	                else stk.pop();
	                break;
	            default:;

	        }
	    }
	    return stk.empty();
    }
};

int main(){
	Solution solution;
	string s = "()[]{}";
	bool res = solution.isValid(s);
	if(res) cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}