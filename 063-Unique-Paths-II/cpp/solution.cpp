/**
* Created by yangyangu
* 2018 / 05
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp = vector<vector<int>>(m, vector<int>(n, 1));
        for(unsigned int i = 0; i < n; ++i){
            if(obstacleGrid[0][i] == 1){
                for(unsigned int k = i; k < n; ++k)
                    dp[0][k] = 0;
            }
        }

        for(unsigned int j = 0; j < m; ++j){
            if(obstacleGrid[j][0] == 1){
                for(unsigned int k = j; k < m; ++k)
                    dp[k][0] = 0;
            }
        }
        for(unsigned int i = 1; i < m; ++i){
            for(unsigned int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

};

int main(){
	Solution solution;
	vector<vector<int>> mat = {
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};
	int res = solution.uniquePathsWithObstacles(mat);
	cout << res << endl;
	return 0;
}