/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (!n) return 1.0;
        if (n < 0) {
            n = -(++n);
            x = 1 / x;
        } else
            n--;
        double result = x;
        while (n) {
            double y = x;
            for (int i = 1; i > 0 && i <= n; i *= 2) {
                result *= y;
                y *= y;
                n -= i;
            }
        }
        return result;
    }
};

int main(){
	Solution solution;
	double x = 2.00000;
	int n = 10;
	double res = solution.myPow(x, n);
	cout << res << endl;
	return 0;
}