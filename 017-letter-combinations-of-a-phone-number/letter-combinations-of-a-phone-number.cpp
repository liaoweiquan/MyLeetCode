// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
private:
    vector<string> res;
    const string letterMap[10] = {
        " ",//0
        "",//1
        "abc",//2
        "def",//3
        "ghi",//4
        "jkl",//5
        "mno",//6
        "pqrs",//7
        "tuv",//8
        "wxyz"//9
    };
    void findCombination(const string &digits, int index, const string &s){
        
        if(index == digits.size()){
            res.push_back(s);
            return;
        }
        char c = digits[index];
        string letters = letterMap[c - '0'];
        for(int i = 0; i < letters.size(); ++i){
            findCombination(digits, index + 1, s + letters[i]);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits == "")
            return res;
        findCombination(digits, 0, "");
        return res;
    }
};
