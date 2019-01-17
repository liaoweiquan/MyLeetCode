// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
// You may assume no duplicates in the array.
//
// Example 1:
//
//
// Input: [1,3,5,6], 5
// Output: 2
//
//
// Example 2:
//
//
// Input: [1,3,5,6], 2
// Output: 1
//
//
// Example 3:
//
//
// Input: [1,3,5,6], 7
// Output: 4
//
//
// Example 4:
//
//
// Input: [1,3,5,6], 0
// Output: 0
//
//


class Solution {
private:
int BinarySearch(vector<int>& nums, int lo, int hi, int target){
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(nums[mid] == target) return mid;
        else if (target > nums[mid]) lo = mid + 1;
        else hi = mid - 1;
    }

    return -1;
}   
public:
    int searchInsert(vector<int>& nums, int target) {
        int re = BinarySearch(nums,0,nums.size()-1,target);
    if(re != -1) return re;
    else{
        if(target < nums[0]) return 0;
        else if(target > nums[nums.size()-1]) return nums.size();
        else{
            for(int i = 1; i <= nums.size() - 1; ++i){
                if(nums[i-1] < target && nums[i] > target) return i;
            }
        }
    }
    }
};
