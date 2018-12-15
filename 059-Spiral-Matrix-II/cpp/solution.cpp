/**
* Created by yangyangu
* 2018 / 08
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n,0));
       	if(!n) return mat;

       	int ul = 0, lc = 0, rc = n - 1 , dl = n - 1;
       	int l = 0, c = 0;
       	int ant = 1, cnt = n * n;
       	while(lc <= rc && ul <= dl){
       		for(c = lc; c <= rc; ++ c){
        		mat[l][c] = ant++;
        		//cout << l << " " << c << endl;
        	}
        	c = rc;
        	++ ul;
        	for(l = ul; l <= dl; ++ l){
        		mat[l][c] = ant++;
        		//cout << l << " " << c << endl;
        	}
        	l = dl;
        	-- rc;
        	for(c = rc; c >= lc; -- c){
        		mat[l][c] = ant++;
        		//cout << l << " " << c << endl;
        	}
        	c = lc;
        	-- dl;
        	for(l = dl; l >= ul; -- l){
        		mat[l][c] = ant++;
        		//cout << l << " " << c << endl;
        	}
        	++ lc;
        	l = ul;
       	}
        return mat;
    }
};

int main(){
	Solution solution;
	int n = 3;
	auto res = solution.generateMatrix(n);
	for(auto i: res){
		for(auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}