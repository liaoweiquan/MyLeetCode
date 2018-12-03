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
    vector<bool> used;
    void dfs(const vector<int>& nums, int index, vector<int>& p){
        if(index == nums.size()){
            res.push_back(p);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!used[i]){
                p.push_back(nums[i]);
                used[i] = true;
                dfs(nums,index + 1, p);
                p.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums.empty())
            return res;
        vector<int> p;
        used = vector<bool>(nums.size(),false);
        dfs(nums, 0, p);
        return res;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {1,2,3};
	vector<vector<int>> res = solution.permute(nums);
	for(auto i : res){
		for(auto j: i){
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}