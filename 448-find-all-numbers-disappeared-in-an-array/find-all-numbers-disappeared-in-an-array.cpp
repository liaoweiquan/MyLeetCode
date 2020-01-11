// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements of [1, n] inclusive that do not appear in this array.
//
// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [5,6]
//
//


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.empty()) return nums;
        vector<int> vt;
    for(int i  = 0; i <= nums.size() - 1; ++i){
        int n = abs(nums[i]) - 1;
        nums[n] = nums[n] > 0 ? -nums[n] :nums[n];
    }
    for(int i = 0; i <= nums.size() - 1; ++i){
        if(nums[i] > 0) vt.push_back(i + 1);
    }

    return vt;
    }
};
