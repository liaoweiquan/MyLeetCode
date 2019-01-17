// Given a string, find the length of the longest substring without repeating characters.
//
//
// Example 1:
//
//
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
//
//
// Example 2:
//
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
//
// Example 3:
//
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
//
//


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
