/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
	    for(char ch: s){
	        if(ch == '(' || ch == '{' || ch == '[')
	            stk.push(ch);
	        else{
	            if(stk.empty())
	                return false;
	            char c = stk.top();
	            stk.pop();
	            char match;
	            if(ch == ')')
	                match = '(';
	            else if(ch == ']')
	                match = '[';
	            else
	                match = '{';
	            if(c != match)
	                return false;
	            
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