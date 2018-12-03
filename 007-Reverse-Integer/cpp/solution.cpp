/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
	    if(x > INT32_MAX || x < INT32_MIN) return 0;
	    bool isNegative = false;
	    if(x < 0){
	        x = -x;
	        isNegative = true;
	    }
	    if(x >= 1 && x <= 9){
	        if(isNegative) return -x;
	        else return x;
	    }
	    int r = 0;
	    while(x > 0){
	        
	        long temp = (long)r * 10;
	        if(temp > INT32_MAX) return 0;
	        r = 10 * r + x % 10;
	        x /= 10;
	    }

	    if(!isNegative)return r;
	    else return -r;
	    
	}
};

int main(){
	Solution solution;
	int num = 123;
	int res = solution.reverse(num);
	cout << res << endl;
	return 0;
}