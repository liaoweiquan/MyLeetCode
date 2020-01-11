// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            if(i == 0 || nums[i] != nums[i - 1]){
                int lo = i + 1, hi = n - 1, sum = 0 - nums[i];
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[lo]);
                        v.push_back(nums[hi]);
                        res.push_back(v);
                        while(lo + 1 < hi && nums[lo] == nums[lo + 1]) ++ lo;
                        while(lo < hi - 1 && nums[hi] == nums[hi - 1]) -- hi;
                        ++ lo;
                        -- hi;
                    }
                    else if(nums[hi] + nums[lo] < sum) ++ lo;
                    else -- hi;
                }
            }
        }

        return res;
    }
};
