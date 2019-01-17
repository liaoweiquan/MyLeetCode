//
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
//
//
//
//
// Note: You may assume the string contain only lowercase letters.
//


class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()) return -1;
        vector<int> vt(26);
        for(int i = 0; i < vt.size();++ i)
            vt[i] = 0;
        for(char ch: s)
            ++ vt[ch - 'a'];
        for(int i = 0; i <= s.size() - 1; ++i){
            if(vt[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
