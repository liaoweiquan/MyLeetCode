// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
//
// Example 2:
//
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
//


class Solution {
private:
    int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    vector<vector<bool>> visited;
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    void dfs(vector<vector<char>>& grid, int x, int y){
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx,newy) && !visited[newx][newy] && grid[newx][newy] == '1')
                dfs(grid, newx, newy);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int res = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == '1' && !visited[i][j]){
                    ++ res;
                    dfs(grid, i, j);
                }
        
        return res;
    }
};
