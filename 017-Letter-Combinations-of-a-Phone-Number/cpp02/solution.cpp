/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

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
int main(){
	Solution solution;
	string digits = "23";
	vector<string> res = solution.letterCombinations(digits);
	for(auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}