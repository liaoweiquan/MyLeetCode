// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
//
//


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
