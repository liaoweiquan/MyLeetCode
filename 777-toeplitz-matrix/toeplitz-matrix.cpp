// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
//
// Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
//  
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,2,3,4],
//   [5,1,2,3],
//   [9,5,1,2]
// ]
// Output: True
// Explanation:
// In the above grid, the diagonals are:
// "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
// In each diagonal all elements are the same, so the answer is True.
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,2],
//   [2,2]
// ]
// Output: False
// Explanation:
// The diagonal "[1, 2]" has different elements.
//
//
//
// Note:
//
//
// 	matrix will be a 2D array of integers.
// 	matrix will have a number of rows and columns in range [1, 20].
// 	matrix[i][j] will be integers in range [0, 99].
//
//
//
// Follow up:
//
//
// 	What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
// 	What if the matrix is so large that you can only load up a partial row into the memory at once?
//
//


class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& matrix){
        if(i + 1 >= matrix.size() || j + 1 >= matrix[0].size())
            return true;
        if(matrix[i+1][j+1] == matrix[i][j])
            return dfs(i+1,j+1,matrix);
        else
            return false;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        for(j = 0; j <= matrix[0].size() - 1; ++j){
            if(!dfs(0,j,matrix)) return false;
        }
        for(i = 0; i <= matrix.size() - 1; ++i){
            if(!dfs(i,0,matrix)) return false;
        }
        return true;
    }
};
