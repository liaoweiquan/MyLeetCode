/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string rom;
        int base[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string str[]={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        while(num != 0){
            if(num >= base[i]){
                num -= base[i];
                rom += str[i];
            }
            else
                ++ i;
        }

        return rom;
    }
};
int main(){
	Solution solution;
	int num = 3;
	string res = solution.intToRoman(num);
	cout << res << endl;
	return 0;
}