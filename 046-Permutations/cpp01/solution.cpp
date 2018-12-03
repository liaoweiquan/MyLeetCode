/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &vt,vector<int> &nums,int cursor,int end){
    if(cursor == end){
        vt.push_back(nums);
    }
    else{
        for(int i = cursor; i <= end; ++i){
            swap(nums[cursor],nums[i]);
            dfs(vt,nums,cursor + 1, end);
            swap(nums[cursor],nums[i]);
        }
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vt;
	    if(nums.size() == 0) return vt;
	    if(nums.size() == 1){
	        vt.push_back(nums);
	        return vt;
	    }

	    dfs(vt,nums,0,nums.size() - 1);
	    return vt;
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