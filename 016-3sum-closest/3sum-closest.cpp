// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minx = nums[0] + nums[1] + nums[nums.size() - 1];
    sort(nums.begin(),nums.end());
    for(int i = 0;i <= nums.size() - 1;++ i){
        int lo = i + 1, hi = nums.size() - 1;
        while(lo < hi){
            int sum = nums[i] + nums[lo] + nums[hi];
            if(sum > target) --hi;
            else ++lo;
            if(abs(sum - target) < abs(minx - target))
                minx = sum;
        }
    }
    return minx;
    }
};
