/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>
using namespace std;
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

int main(){
	Solution solution;
	int n = 4;
	auto res = solution.solveNQueens(n);
	for(auto i: res){
		for(auto j: i)
			cout << j << endl;
		cout << endl;
	}
	return 0;
}