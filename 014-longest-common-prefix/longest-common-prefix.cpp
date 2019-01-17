// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
// Example 1:
//
//
// Input: ["flower","flow","flight"]
// Output: "fl"
//
//
// Example 2:
//
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
// Note:
//
// All given inputs are in lowercase letters a-z.
//


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
