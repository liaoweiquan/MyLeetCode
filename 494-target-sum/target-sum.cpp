//
// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
//
//
// Find out how many ways to assign symbols to make sum of integers equal to target S.  
//
//
// Example 1:
//
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 
//
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
//
// There are 5 ways to assign symbols to make the sum of nums be target 3.
//
//
//
// Note:
//
// The length of the given array is positive and will not exceed 20. 
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.
//
//


class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = 0;
        for(auto &num: nums){
            sum += num;
        }
        return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1);
        
    }
    int subsetSum(vector<int> &nums, int s){
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        for(int num: nums){
            for(int i = s; i >= num; -- i)
                dp[i] += dp[i - num];
        }
        return dp[s];
    }
};
