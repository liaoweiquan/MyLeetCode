// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
//
// Example 1:
//
// Input: [1, 2, 2, 3, 1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
//
//
//
//
// Example 2:
//
// Input: [1,2,2,3,1,4,2]
// Output: 6
//
//
//
// Note:
// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.
//


/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (48.49%)
 * Total Accepted:    39.4K
 * Total Submissions: 81K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * 
 * 
 * 
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 * 
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        vector<int> cnt(50000,0);
        for(int num: nums){
            ++ cnt[num];
        }
        
        int maxn = cnt[0];
        for(int c: cnt){
            if(c > maxn){
                maxn = c;
            }
        }
        set<int> max_list;
        for(int i = 0; i < n; ++i){
            if(cnt[nums[i]] == maxn){
                max_list.insert(nums[i]);
            }
        }
        vector<int> res;
        for(int m: max_list){
            int lt = 0, gt = n - 1;
            while(lt + 1 < n && nums[lt] != m) ++ lt;
            while(gt - 1 >= 0 && nums[gt] != m) -- gt;
            res.push_back(gt - lt + 1);
        }
        if(res.size() == 0){
            return 0;
        }
        int minx = res[0];
        for(int re: res){
            if(re < minx){
                minx = re;
            }
        }
        return minx;
    }
};
