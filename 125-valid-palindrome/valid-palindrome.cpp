// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


class Solution {
public:
    bool isNeed(char ch){
        if(ch >= '0' && ch <= '9') return true;
        else if(ch >= 'A' && ch <= 'Z') return true;
        else if(ch >= 'a' && ch <= 'z') return true;
        return false;
    }
    bool isEqual(char a, char b){
        if(a == b) return true;
        char x = a >= 'A' && a <= 'Z' ? tolower(a) : a;
        char y = b >= 'A' && b <= 'Z' ? tolower(b) : b;
        if(x == y) return true;
        return false;
    }
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        int n = s.size();
        int it = 0, jt = n - 1;
        while(it <= jt){
            while(it + 1 <= jt && !isNeed(s[it])) ++it;
            while(jt - 1 >= it && !isNeed(s[jt])) --jt;
            if(isEqual(s[it],s[jt])){
                ++ it;
                -- jt;
            }
            else return false;
        }
        
        return true;
    }
};
