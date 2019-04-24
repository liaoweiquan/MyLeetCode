//
// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
// Note:
//
//
// 	All numbers will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: k = 3, n = 7
// Output: [[1,2,4]]
//
//
// Example 2:
//
//
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]
//
//


class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& vec, int k, int n, int sum, int pos){
        if(vec.size() == k){
            if(sum == n)
                res.push_back(vec);
            return;
        }
        for(int i = pos; i <= 9; ++ i){
            vec.push_back(i);
            dfs(vec, k, n, sum + i, i + 1);
            vec.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec;
        dfs(vec, k, n, 0, 1);
        return res;
    }
};
