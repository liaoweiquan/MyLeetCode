/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
	        return INT_MAX;
	    int sign = ((dividend < 0) ^ (divisor <0)) ? -1 : 1;
	    long long dvd = labs(dividend);
	    long long dvs = labs(divisor);
	    int re = 0;
	    while(dvd >= dvs){
	        long long t = dvs, mul = 1;
	        while(dvd >= (t << 1)){
	            t <<= 1;
	            mul <<= 1;
	        }
	        dvd -= t;
	        re += mul;
	    }

	    return sign == 1 ? re : -re;
    }
};

int main(){
	Solution solution;
	int dividend = 10, divisor = 3;
	int res = solution.divide(dividend, divisor);
	cout << res << endl;
	return 0;
}