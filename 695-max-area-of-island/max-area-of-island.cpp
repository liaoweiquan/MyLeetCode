// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//
// Example 1:
//
//
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
//
// Example 2:
//
//
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
//
// Note: The length of each dimension in the given grid does not exceed 50.
//


class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int search(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1 || grid[x][y] == 0){
            return 0;
        }
        grid[x][y] = -1;
        return 1 + search(grid,x + 1, y) + search(grid,x - 1, y) + search(grid,x, y + 1) + search(grid,x, y - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxn = 0;
        for(int i = 0; i < m; ++ i){
            for(int j = 0; j < n; ++ j){
                if(grid[i][j] == 1){
                    maxn = max(maxn, search(grid, i, j));
                }
            }
        }
        return maxn;
    }
};
