/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void dfs(int n, int k, int start, vector<int>& c){
        if(c.size() == k){
            res.push_back(c);
            return;
        }
        for(int i = start;i <= n - (k - c.size()) + 1 ; ++i){
            c.push_back(i);
            dfs(n, k, i + 1, c);
            c.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        
        res.clear();
        if(n <= 0 || k <= 0 || k > n)
            return res;
        
        vector<int> c;
        dfs(n, k, 1, c);
        return res;
    }
};

int main(){
	Solution solution;
	int n = 4, k = 2;
	auto res = solution.combine(n, k);
	for(auto i: res){
		for(auto j: i){
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}