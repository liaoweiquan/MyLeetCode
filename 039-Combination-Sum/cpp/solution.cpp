/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>&can,vector<int>&c, int t, int s,int start){
        if(t == s){
            res.push_back(c);
            return;
        }
        if(s > t) return;
        for(int i = start; i <= can.size() - 1; ++i){
            c.push_back(can[i]);
            dfs(can, c, t, s + can[i],i);
            c.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        if(candidates.empty())
            return res;
        vector<int> c;
        dfs(candidates,c,target, 0,0);
        return res;
    }
};
int main(){
	Solution solution;
	vector<int> candidates = {2, 3, 6, 7};
	int target = 7;
	vector<vector<int>> res = solution.combinationSum(candidates, target);
	for(auto i: res){
		for(auto j: i){
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}