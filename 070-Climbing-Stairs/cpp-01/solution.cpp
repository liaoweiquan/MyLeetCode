/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n >= 1 && n <= 3) return n;
        int a = 2, b = 3;
        n -= 3;
        while(n >= 1){
            int t = b;
            b = a+b;
            a = t;
            --n;
        }
        return b;
    }
};

int main(){
	Solution solution;
	int n = 2;
	int res = solution.climbStairs(n);
	cout << res << endl;
	return 0;
}