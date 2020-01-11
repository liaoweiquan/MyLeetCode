// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


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
