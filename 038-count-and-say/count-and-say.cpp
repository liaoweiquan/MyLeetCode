// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
//
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.
//
//  
//
// Example 1:
//
//
// Input: 1
// Output: "1"
//
//
// Example 2:
//
//
// Input: 4
// Output: "1211"
//


class Solution {
public:
    string countAndSay(int n) {
       string s = "1";
    if(n == 1 || n == 0) return s;
    string q;
    string str[10]={"0","1","2","3","4","5","6","7","8","9"};
    while(-- n){
        int i = 0, len = s.size();
        q.clear();
        while(i <= len - 1){
            int cnt = 1;
            while(i + 1 <= len - 1 && s[i] == s[i + 1]){
                ++ i;
                cnt ++;
            }
            string t;
            q += str[cnt];
            q += s[i];
            ++ i;
        }
        s.clear();
        s = q;
    }
    return s;
    }
};
