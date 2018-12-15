/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int climbStairs(int n) {
        vector<int> memo = vector<int>(n + 1, -1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i = 2; i <=n; ++i)
            memo[i] = memo[i - 1] + memo[i - 2];
        
        return memo[n];
    }
};

int main(){
	Solution solution;
	int n = 2;
	int res = solution.climbStairs(n);
	cout << res << endl;
	return 0;
}