//
// Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).
//
//
// Example 1:
//
// Input: [1,3,5,4,7]
// Output: 3
// Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
// Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
//
//
//
// Example 2:
//
// Input: [2,2,2,2,2]
// Output: 1
// Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
//
//
//
// Note:
// Length of the array will not exceed 10,000.
//


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> vt(nums.size(),1);
        for(int i = 1; i <= nums.size() - 1; ++i){
            if(nums[i] <= nums[i - 1])
                continue;
            else if(nums[i] > nums[i - 1])
                vt[i] = vt[i - 1] + 1;
        }
        int maxn = vt[0];
        for(int n : vt)
            if(maxn < n)
                maxn = n;
        return maxn;
    }
};
