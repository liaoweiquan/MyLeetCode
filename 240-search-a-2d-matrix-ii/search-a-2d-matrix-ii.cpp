// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted in ascending from left to right.
// 	Integers in each column are sorted in ascending from top to bottom.
//
//
// Example:
//
// Consider the following matrix:
//
//
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
//
//
// Given target = 5, return true.
//
// Given target = 20, return false.
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0){
            int num = matrix[i][j];
            if(num == target)
                return true;
            else if(num > target)
                -- j;
            else
                ++ i;
        }
        return false;
    }
};
