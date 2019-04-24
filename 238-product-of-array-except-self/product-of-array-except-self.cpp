// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
// Example:
//
//
// Input:  [1,2,3,4]
// Output: [24,12,8,6]
//
//
// Note: Please solve it without division and in O(n).
//
// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
//


class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {

        size_t size = nums.size();
        vector<int> res(size, 0);
        int left = 1;
        for(auto i = 0; i < size; ++ i){
            res[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for(int j = size - 1; j >= 0; -- j){
            res[j] = res[j] * right;
            right *= nums[j];
        }
        return res;
    }
};
