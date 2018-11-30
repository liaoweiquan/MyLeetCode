/**
* Created by yangyangu
* 2018 / 02
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = -1;
        int res = 0;
        while(l < s.size()){
            if(r + 1 < s.size() && !freq[s[r+1]])
                ++freq[s[++r]];
            else
                --freq[s[l++]];
            res = max(res,r - l + 1);
        }
        
        return res;
    }
};

int main(){
	Solution solution;
	string str = "abcabcbb";
	int len = solution.lengthOfLongestSubstring(str);
	cout << len << endl;
	return 0;
}