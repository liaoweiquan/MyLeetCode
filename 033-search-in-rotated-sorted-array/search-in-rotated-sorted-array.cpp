// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
private:
    int BinarySearch(vector<int>& nums, int lo, int hi, int target){

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(nums[mid] == target) return mid;
        else if(target > nums[mid]){
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return -1;
}
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
        return -1;
    if(nums.size() == 1 && nums[0] == target)
        return 0;
    int p = -1;
    for(int i = 1;i <= nums.size() - 1;++ i){
        if(nums[i] < nums[i-1]){
            p = i;
            break;
        }
    }
    int re = BinarySearch(nums, 0, p - 1, target);
    if(re == -1){
        re = BinarySearch(nums, p, nums.size() - 1, target);
    }
    return re;
    }
};
