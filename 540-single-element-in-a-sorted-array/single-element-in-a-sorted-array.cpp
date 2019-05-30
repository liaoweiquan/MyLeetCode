// Given a sorted array consisting of only integers where every element appears exactly twice except for one element which appears exactly once. Find this single element that appears only once.
//
//  
//
// Example 1:
//
//
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
//
//
// Example 2:
//
//
// Input: [3,3,7,7,10,11,11]
// Output: 10
//
//
//  
//
// Note: Your solution should run in O(log n) time and O(1) space.
//


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int lt = 0, gt = nums.size() - 1;
        while(lt < gt){
            int mid = (gt - lt) / 2 + lt;
            if(mid % 2 == 0){
                if(nums[mid] == nums[mid - 1]){
                    gt = mid - 2;
                }else if(nums[mid] == nums[mid + 1]){
                    lt = mid + 2;
                }else{
                    return nums[mid];
                }
            }else{
                if(nums[mid] == nums[mid + 1]){
                    gt = mid - 1;
                }else if(nums[mid] == nums[mid - 1]){
                    lt = mid + 1;
                }else{
                    return nums[mid];
                }
            }
        }
        return nums[lt];
    }
};
