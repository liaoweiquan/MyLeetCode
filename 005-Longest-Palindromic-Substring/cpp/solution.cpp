/**
* Created by yangyangu
* 2017 / 11
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s){
	    string t = "$#";
	    for (int i = 0; i < s.size(); ++i) {
	        t += s[i];
	        t += "#";
	    }
	    // Process t
	    vector<int> p(t.size(), 0);
	    int mx = 0, id = 0, resLen = 0, resCenter = 0;
	    for (int i = 1; i < t.size(); ++i) {
	        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
	        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
	        if (mx < i + p[i]) {
	            mx = i + p[i];
	            id = i;
	        }
	        if (resLen < p[i]) {
	            resLen = p[i];
	            resCenter = i;
	        }
	    }
	    return s.substr((resCenter - resLen) / 2, resLen - 1);
	}
};

int main(){
	Solution solution;
	string str = "babad";
	string res = solution.longestPalindrome(str);
	cout << res << endl;
	return 0;
}