// Given a set of distinct integers, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
//


class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int> tmp, int pos){
        if(pos >= nums.size()){
            res.push_back(tmp);
            return;
        }
        dfs(nums, tmp, pos + 1);
        tmp.push_back(nums[pos]);
        dfs(nums, tmp, pos + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())
            return res;
        vector<int> tmp;
        dfs(nums, tmp, 0);
        return res;
    }
};
