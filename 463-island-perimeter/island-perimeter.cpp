// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
//
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
//
// The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
//  
//
// Example:
//
//
// Input:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
//
// Output: 16
//
// Explanation: The perimeter is the 16 yellow stripes in the image below:
//
//
//
//


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid){
    int sum = 0;
    for(int i = 0 ;i <= grid.size() - 1; ++i){
        for(int j = 0; j <= grid[i].size() - 1; ++j){
            if(!grid[i][j]) continue;

            if(j - 1 == -1 ) ++ sum;
            if(j + 1 == grid[i].size()) ++ sum;
            if(i - 1 == -1 ) ++ sum;
            if(i + 1 == grid.size()) ++ sum;
            if(i >= 0 && i + 1 <=grid.size() - 1 && !grid[i + 1][j]) ++ sum;
            if(i - 1 >= 0 && i<=grid.size() - 1 && !grid[i - 1][j]) ++ sum;
            if(j >= 0 && j + 1 <= grid[i].size() - 1 && !grid[i][j + 1]) ++ sum;
            if(j - 1 >= 0 && j<=grid[i].size() - 1 && !grid[i][j - 1]) ++ sum;

        }
    }
    return sum;
}
};
