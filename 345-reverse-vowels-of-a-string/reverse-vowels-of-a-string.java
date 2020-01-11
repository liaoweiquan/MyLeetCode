// Write a function that takes a string as input and reverse only the vowels of a string.
//
// Example 1:
//
//
// Input: "hello"
// Output: "holle"
//
//
//
// Example 2:
//
//
// Input: "leetcode"
// Output: "leotcede"
//
//
// Note:
// The vowels does not include the letter "y".
//
//  
//


/*
 * @lc app=leetcode id=345 lang=java
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (40.54%)
 * Total Accepted:    137.5K
 * Total Submissions: 339.2K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
class Solution {
    public boolean isVowels(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    public void myswap(char a[], int l, int r){
        char t = a[l];
        a[l] = a[r];
        a[r] = t;
    }
    public String reverseVowels(String s) {
        
        int lt = 0, gt = s.length() - 1;
        char a[] = s.toCharArray();
        while(lt < gt){
            if(isVowels(a[lt]) && isVowels(a[gt])){
                myswap(a, lt, gt);
                ++ lt;
                -- gt;
            }else if(isVowels(a[lt])){
                -- gt;
            }else{
                ++ lt;
            }
        }
        return new String(a);
    }
}

