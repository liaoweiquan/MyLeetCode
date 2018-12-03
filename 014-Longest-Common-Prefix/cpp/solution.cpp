/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int i = 0;
        vector<string>::iterator it = strs.begin();
        string s = *it;

        for(++ it;it != strs.end(); ++it){
            string r;
            string t = *it;
            for(i = 0; i <= t.length()-1; ++i){
                if(s[i] == t[i]){
                    r += t[i];
                }
                else break;
            }
            s = r;
        }
        return s;
    }
};

int main(){
	Solution solution;
	vector<string> strs = {"flower","flow","flight"};
	string res = solution.longestCommonPrefix(strs);
	cout << res << endl;
	return 0;
}