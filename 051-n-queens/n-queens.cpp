// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// Example:
//
//
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
//


class Solution {
private:
    vector<vector<string>> res;
    vector<bool> col,dia1,dia2;
    vector<string> generateBoard(int n, vector<int> &row){
        vector<string> board(n, string(n,'.'));
        for(int i = 0; i < n; ++i)
            board[i][row[i]] = 'Q';
        return board;
    }
    void putQueen(int n, int index, vector<int> &row){
        if(index == n){
            res.push_back(generateBoard(n,row));
            return;
        }
        for(int i = 0; i < n; ++i)
            if(!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]){
                row.push_back(i);
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;
                col[i] = true;
                putQueen(n, index + 1, row);
                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                row.pop_back();
            }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * n - 1, false);
        dia2 = vector<bool>(2 * n - 1, false);
        vector<int> row;
        putQueen(n, 0, row);
        
        return res;
    }
};
