// Given a word, you need to judge whether the usage of capitals in it is right or not.
//
// We define the usage of capitals in a word to be right when one of the following cases holds:
//
//
// 	All letters in this word are capitals, like "USA".
// 	All letters in this word are not capitals, like "leetcode".
// 	Only the first letter in this word is capital, like "Google".
//
// Otherwise, we define that this word doesn't use capitals in a right way.
//
//  
//
// Example 1:
//
//
// Input: "USA"
// Output: True
//
//
//  
//
// Example 2:
//
//
// Input: "FlaG"
// Output: False
//
//
//  
//
// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
//


class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
    if(n == 0 || n == 1) return true;
    if(word[0] >= 'a' && word[0] <= 'z'){
        for(char c : word){
            if(c >= 'A' && c <= 'Z') return false;
        }
        return true;
    }
    else if(word[0] >= 'A' && word [0] <= 'Z'){
        if(word[1] >= 'A' && word[1] <= 'Z'){
            for(int i = 2; i <= n - 1; ++i){
                if(word[i] >= 'a' && word[i] <= 'z') return false;
            }
            return true;
        }
        else if(word[1] >= 'a' && word [1] <='z'){
            for(int i = 2; i <= n - 1; ++i){
                if(word[i] >= 'A' && word[i] <= 'Z') return false;
            }
            return true;
        }
    }
    }
};
