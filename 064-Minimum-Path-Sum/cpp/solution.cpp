/**
* Created by yangyangu
* 2018 / 05
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(unsigned int i = 0; i < grid.size(); ++i){
            for(unsigned int j = 0; j < grid[i].size(); ++j){
                if(!i && !j)
                    continue;
                if(i == 0){
                    grid[i][j] += grid[i][j - 1];
                }
                else if(j == 0){
                    grid[i][j] += grid[i - 1][j];
                }
                else{
                    grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
                }

            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};

int main(){
	Solution solution;
	vector<vector<int>> mat = {
		{1,3,1},
		{1,5,1},
		{4,2,1}
	};
	int res = solution.minPathSum(mat);
	cout << res << endl;
	return 0;
}