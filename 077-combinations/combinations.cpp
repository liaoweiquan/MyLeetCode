// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//
//


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
