/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp = vector<vector<int>>(m,vector<int>(n,1));
        //dp[0][0] = 1;
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                dp[i][j] = dp[i -1][j] + dp[i][j - 1];
        
        
        return dp[m - 1][n - 1];
    }
};

int main(){
	Solution solution;
	int m = 7, n = 3;
	int res = solution.uniquePaths(m, n);
	cout << res << endl;
	return 0;
}