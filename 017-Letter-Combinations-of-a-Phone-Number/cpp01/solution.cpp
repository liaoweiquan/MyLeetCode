/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits){
	    vector<string> v;
	    queue<string> q;

	    if(digits.size() == 0){
	        return v;
	    }
	    char str[10][6]={
	            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
	    };
	    for(int i = 0; i <= digits.size()-1; ++i){
	        int t = digits[i] - '0';
	        int len = strlen(str[t]);
	        if(i == 0){
	            for(int j = 0;j <= len-1; ++j){
	                string s;
	                s.push_back(str[t][j]);
	                q.push(s);
	            }
	        }
	        else{
	            queue<string> p;
	            while(!q.empty()){
	                for(int j = 0;j <= len-1; ++j){
	                    string s = q.front();
	                    //if(j == len-1) q.pop();
	                    string r;
	                    r.push_back(str[t][j]);
	                    s += r;
	                    p.push(s);
	                }
	                q.pop();
	            }
	            while(!p.empty()){
	                q.push(p.front());
	                p.pop();
	            }
	        }

	    }
	    while(!q.empty()){
	        v.push_back(q.front());
	        q.pop();
	    }
	    return v;
	}
};
int main(){
	Solution solution;
	string digits = "23";
	vector<string> res = solution.letterCombinations(digits);
	for(auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}