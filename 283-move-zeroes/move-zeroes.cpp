// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
// Example:
//
//
// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Note:
//
//
// 	You must do this in-place without making a copy of the array.
// 	Minimize the total number of operations.
//


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i  = 0; i <= n - 1; ++i){
            if(nums[i])
                if(i != k)
                    swap( nums[k++] , nums[i]);
            else
                ++k;
        }
        
    }
};
