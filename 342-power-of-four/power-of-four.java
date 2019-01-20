// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
// Example 1:
//
//
// Input: 16
// Output: true
//
//
//
// Example 2:
//
//
// Input: 5
// Output: false
//
//
// Follow up: Could you solve it without loops/recursion?


/*
 * @lc app=leetcode id=342 lang=java
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (39.85%)
 * Total Accepted:    102.8K
 * Total Submissions: 257.9K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */
class Solution {
    public boolean isPowerOfFour(int num) {
        return num > 0 && (int)(Math.log10(num) / Math.log10(4)) - Math.log10(num) / Math.log10(4) == 0;
    }
}

