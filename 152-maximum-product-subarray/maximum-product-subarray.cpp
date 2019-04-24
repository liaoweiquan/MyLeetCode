// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// Example 1:
//
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
//
// Example 2:
//
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxn = INT_MIN, size = nums.size();
        for (auto i = 0; i < size; ++i) {
            auto tmp = nums[i];
            maxn = max(maxn, tmp);
            for (auto j = i + 1; j < size; ++j) {
                tmp *= nums[j];
                maxn = max(maxn, tmp);
            }
        }
        return maxn;
    }
};
