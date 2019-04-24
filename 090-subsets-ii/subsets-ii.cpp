// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
//
//


struct numcnt{
    int v, cnt;
    numcnt(int _v, int _cnt): v(_v), cnt(_cnt){}
};
class Solution {

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> res;
        res.push_back({});
        if(nums.empty())
            return res;
        vector<numcnt *> numc;
        unordered_map<int,numcnt*> mpt;
        for(auto &num: nums){
            if(mpt.count(num) == 0){
                auto p = new numcnt(num, 1);
                mpt[num] = p;
                numc.push_back(p);
            }else{
                ++ mpt[num]->cnt;
            }
        }
        int size = numc.size();
        int prev_size = 1;
        for(int i = 0; i < size; ++ i){
            int tmp = numc[i]->v;
            int tmp_cnt = numc[i]->cnt;
            for(int j = 0; j < prev_size; ++ j){
                vector<int> v = res[j];
                for(int r = 1; r <= tmp_cnt; ++ r){
                    v.push_back(tmp);
                    res.push_back(v);
                }
            }
            prev_size *= (tmp_cnt + 1);
        }
        return res;
    }
};
