// Given a string, your task is to count how many palindromic substrings in this string.
//
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
// Example 1:
//
//
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
//
//
//  
//
// Example 2:
//
//
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//
//
//  
//
// Note:
//
//
// 	The input string length won't exceed 1000.
//
//
//  
//


class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0, n = s.size();
        for(int i = 0; i < n; ++ i){
            ++ cnt;
            for(int j = i + 1; j < n; ++ j){
                int begin = i, end = j;
                bool fl = true;
                while(begin <= end){
                    if(s[begin] == s[end]){
                        ++ begin;
                        -- end;
                    }else{
                        fl = false;
                        break;
                    }
                }
                if(fl)
                    ++ cnt;
            }
        }
        return cnt;
    }
};
