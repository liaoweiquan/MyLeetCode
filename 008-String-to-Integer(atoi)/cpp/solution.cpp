/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    if(str.length() == 0) return 0;
    long long result = 0;
    int sigh = 1,i = 0;
    
    while(str[i] == ' '){
        if(str[i] == ' ') ++i;
    }
    
    if(str[i] == '+') ++i;
    else if(str[i] == '-'){
        sigh = -1;
        ++ i;
    }
    for(int j = i;j < str.length(); ++ j){
        if(str[j] >= '0' && str[j] <= '9'){
            result = result*10+str[j] - '0';
            
            if(result > INT32_MAX)
                return sigh < 0 ? INT32_MIN : INT32_MAX;
        }
        else break;
    }
    result *= sigh;
    
    return (int)result;
}
};

int main(){
	Solution solution;
	string str = "   -42";
	int res = solution.myAtoi(str);
	cout << res << endl;
	return 0;
}