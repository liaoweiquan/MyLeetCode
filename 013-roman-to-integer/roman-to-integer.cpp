// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
//
//
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
//
// For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
//
//
// 	I can be placed before V (5) and X (10) to make 4 and 9. 
// 	X can be placed before L (50) and C (100) to make 40 and 90. 
// 	C can be placed before D (500) and M (1000) to make 400 and 900.
//
//
// Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
//
// Example 1:
//
//
// Input: "III"
// Output: 3
//
// Example 2:
//
//
// Input: "IV"
// Output: 4
//
// Example 3:
//
//
// Input: "IX"
// Output: 9
//
// Example 4:
//
//
// Input: "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
//
//
// Example 5:
//
//
// Input: "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
//


class Solution {
public:
    int romanToInt(string s) {
        int re = 0;
    int i = 0;
    while(i <= s.length() -1){
        if(s[i] == 'M'){
            ++ i;
            re +=1000;
        }
        else if(s[i] == 'C'){
            if(i+1 <= s.length()-1){
                if(s[i+1] == 'M'){
                    i += 2;
                    re += 900;
                }
                else if(s[i+1] == 'D'){
                    i += 2;
                    re +=400;
                }
                else{
                    ++ i;
                    re += 100;
                }
            }
            else{
                ++ i;
                re += 100;
            }
        }
        else if(s[i] == 'D'){
            ++i;
            re += 500;
        }
        else if(s[i] == 'X'){
            if(i+1 <= s.length()-1){
                if(s[i+1] == 'C'){
                    i += 2;
                    re += 90;
                }
                else if(s[i+1] == 'L'){
                    i += 2;
                    re += 40;
                }
                else{
                    ++ i;
                    re += 10;
                }
            }
            else{
                ++ i;
                re += 10;
            }
        }
        else if(s[i] == 'L'){
            ++ i;
            re += 50;
        }
        else if(s[i] == 'I'){
            if(i+1 <= s.length()-1){
                if(s[i+1] == 'X'){
                    i += 2;
                    re += 9;
                }
                else if(s[i+1] == 'V'){
                    i += 2;
                    re += 4;
                }
                else{
                    ++i ;
                    re +=1;
                }
            }
            else{
                ++ i;
                re += 1;
            }
        }
        else if(s[i] == 'V'){
            ++ i;
            re += 5;
        }

    }
    return re;
    }
};
