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
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
    vector<int>::iterator it;
    int len = 0;
    sort(nums.begin(),nums.end());
    for(it = nums.begin(); it != nums.end(); ++it){
        ++ len;
    }
    sort(nums.begin(),nums.end());
    for(int i = 0;i <= len-1; ++ i){
        if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
            int lo = i + 1, hi = len -1, sum = 0 - nums[i];
            while(lo < hi){
                if(nums[lo] + nums[hi] == sum){
                    vector<int> vt;
                    vt.push_back(nums[i]);
                    vt.push_back(nums[lo]);
                    vt.push_back(nums[hi]);
                    v.push_back(vt);
                    while(lo < hi && nums[lo] == nums[lo+1]) ++lo;
                    while(lo < hi && nums[hi] == nums[hi-1]) --hi;
                    ++lo;
                    --hi;
                }
                else if(nums[lo] + nums[hi] < sum) ++lo;
                else --hi;
            }
        }
    }
    return v;
    }
};
