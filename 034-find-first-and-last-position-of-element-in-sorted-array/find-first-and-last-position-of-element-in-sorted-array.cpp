// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
    if(nums.size() == 0 || (nums.size() == 1 && nums[0] != target)){
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
    int lo = 0, hi = nums.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] == target){
            int r = mid;
            while(r+1 <= nums.size() - 1 && nums[r+1] == target) ++r;
            int l = mid;
            while(l-1 >= 0 && nums[l-1] == target) --l;
            v.push_back(l);
            v.push_back(r);
            return v;
        }
        else if (nums[mid] > target){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    v.push_back(-1);
    v.push_back(-1);
    return v;
    }
};
