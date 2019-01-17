// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
//


class Solution {
private:
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    vector<vector<bool>> visited;
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    bool searchWord(const vector<vector<char>> &board, const string& word, int index, int startx, int starty ){
        if(index == word.size() - 1)
            return board[startx][starty] == word[index];
        
        if(board[startx][starty] == word[index]){
            visited[startx][starty] = true;
            for(int i = 0; i < 4; ++i){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if(inArea(newx,newy) && !visited[newx][newy] && searchWord(board, word, index + 1, newx, newy))
                    return true;
            }
            visited[startx][starty] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[i].size(); ++j)
                if(searchWord(board, word, 0, i, j))
                    return true;
        return false;
    }
};
