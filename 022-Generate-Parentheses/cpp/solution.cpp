/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
	    get(v, "", 0, 0, n);
	    return v;
    }
};

int main(){
	Solution solution;
	int n = 3;
	vector<string> res = solution.generateParenthesis(n);
	for(auto i : res){
		cout << i << endl;
	}
	return 0;
}