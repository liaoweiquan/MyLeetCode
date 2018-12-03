/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
	    for(int i = 0; i < n / 2; ++i){
	        for(int j = 0; j <= n - 1; ++j){
	            swap(matrix[i][j],matrix[n - i - 1][j]);
	        }
	    }
	    for(int i = 0; i <= n - 1; ++i){
	        for(int j = i + 1; j <= n - 1; ++j){
	            swap(matrix[i][j],matrix[j][i]);
	        }
	    }
    }
};

int main(){
	Solution solution;
	vector<vector<int>> matrix = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	solution.rotate(matrix);
	for(auto i : matrix){
		for(auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}