// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
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
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
//


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
