// Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
//
// Please note that the string does not contain any non-printable characters.
//
// Example:
//
// Input: "Hello, my name is John"
// Output: 5
//
//


/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.55%)
 * Total Accepted:    49.6K
 * Total Submissions: 135.6K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    bool isChar(char ch){
        return ch != ' ';
    }
    int countSegments(string s) {
        if(s == ""){
            return 0;
        }
        int cnt = 0;
        int i = 0, state = 0, n = s.size();
        while(i < n && !isChar(s[i])) ++ i;
        if(i == n) return cnt;
        state = 1;
        for(; i < n; ++ i){
            if((state == 1 && isChar(s[i])) || (state == 0 && !isChar(s[i]))){
                continue;
            }else if(state == 1 && !isChar(s[i])){
                cnt += 1;
                state = 0;
            }else if(state == 0 && isChar(s[i])){
                state = 1;
            }
        }
        return state == 1 ? cnt + 1 : cnt;
    }
};

