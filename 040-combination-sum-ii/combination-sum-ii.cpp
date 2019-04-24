// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates,vector<int>& tmp, int pos, int target){
        if(target == 0) {
            res.push_back(tmp);
        }else{
            for(auto i = pos; i < candidates.size() && candidates[i] <= target; ++ i){
                if(i != pos && candidates[i] == candidates[i - 1])
                    continue;
                tmp.push_back(candidates[i]);
                dfs(candidates, tmp, i + 1, target - candidates[i]);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, tmp, 0, target);
        return res;
    }
};
