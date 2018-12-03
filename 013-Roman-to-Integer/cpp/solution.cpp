/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <string>
using namespace std;

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

int main(){
	Solution solution;
	// example 1
	string roman1 = "III";
	int res1 = solution.romanToInt(roman1);
	cout << res1 << endl;
	// example 5
	string roman2 = "MCMXCIV";
	int res2 = solution.romanToInt(roman2);
	cout << res2 << endl;
	return 0;
}