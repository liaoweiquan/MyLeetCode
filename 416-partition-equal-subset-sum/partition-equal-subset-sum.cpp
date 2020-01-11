// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
// Note:
//
//
// 	Each of the array element will not exceed 100.
// 	The array size will not exceed 200.
//
//
//  
//
// Example 1:
//
//
// Input: [1, 5, 11, 5]
//
// Output: true
//
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
//  
//
// Example 2:
//
//
// Input: [1, 2, 3, 5]
//
// Output: false
//
// Explanation: The array cannot be partitioned into equal sum subsets.
//
//
//  
//


class Solution {
private:
    vector<vector<int>> memo;
    bool tryPartition(vector<int>& nums, int index, int sum){
        if(sum == 0)
            return true;
        if(sum < 0 || index < 0)
            return false;
        if(memo[index][sum] != -1)
            return memo[index][sum] == 1;
        //return tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index]);
        memo[index][sum] = (tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index])) ? 1: 0;
        return memo[index][sum] == 1;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 != 0)
            return false;
        memo = vector<vector<int>>(nums.size(), vector<int>(sum/2+1,-1));
        return tryPartition(nums, nums.size() - 1, sum / 2);
    }
};
