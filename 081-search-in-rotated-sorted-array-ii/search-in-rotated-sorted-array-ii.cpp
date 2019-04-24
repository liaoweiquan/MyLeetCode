// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
//
// Example 2:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// Follow up:
//
//
// 	This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// 	Would this affect the run-time complexity? How and why?
//
//


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, size = nums.size();
        for(i = 0; i < size; ++ i){
            if(nums[i] == target)
                return true;
            if(i >= 1 && nums[i] < nums[i - 1])
                break;
        }
        int lt = i, gt = size - 1;
        while(lt <= gt){
            int mid = lt + (gt - lt) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                gt = mid - 1;
            else
                lt = mid + 1;
        }
        return false;
    }
};
