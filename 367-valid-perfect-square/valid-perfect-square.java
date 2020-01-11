// Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
// Note: Do not use any built-in library function such as sqrt.
//
// Example 1:
//
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
// Input: 14
// Output: false
//
//
//


/*
 * @lc app=leetcode id=367 lang=java
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (39.17%)
 * Total Accepted:    95.5K
 * Total Submissions: 243.9K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
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
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */
class Solution {
    public boolean isPerfectSquare(int num) {
        for(int i = 1; num > 0; i += 2){
            num -= i;
        }
        return num == 0;
    }
}

