// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
//
//
// Input: [3,4,5,1,2] 
// Output: 1
//
//
// Example 2:
//
//
// Input: [4,5,6,7,0,1,2]
// Output: 0
//
//


class Solution {
public:
    int findMin(vector<int>& nums) {
        int lt = 0, gt = nums.size() - 1, size = nums.size();
        while(lt <= gt){
            int mid = lt + (gt - lt) / 2;
            if(mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            else if(nums[mid] > nums[size - 1])
                lt = mid + 1;
            else
                gt = mid - 1;
        }
        return nums[lt];
    }
};
