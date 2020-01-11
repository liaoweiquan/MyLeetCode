// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a maximal substring consisting of non-space characters only.
//
// Example:
//
//
// Input: "Hello World"
// Output: 5
//
//
//  
//


/*
 * @lc app=leetcode id=58 lang=java
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.13%)
 * Total Accepted:    236.7K
 * Total Submissions: 736.6K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
    public int lengthOfLastWord(String s) {
        if(s == null || s.length() == 0){
            return 0;
        }
        int len = s.length();
        int cnt = 0;
        for(int i = len - 1; i >= 0; -- i){
            if(s.charAt(i) != ' '){
                ++ cnt;
            }
            if(s.charAt(i)== ' ' && cnt != 0){
                return cnt;
            }
        }

        return cnt;
    }
}

