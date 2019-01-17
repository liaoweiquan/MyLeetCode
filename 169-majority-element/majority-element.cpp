// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
// You may assume that the array is non-empty and the majority element always exist in the array.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: 3
//
// Example 2:
//
//
// Input: [2,2,1,1,1,2,2]
// Output: 2
//
//


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> arg(nums.size(),1);
        sort(nums.begin(),nums.end());
        int it = 0, n = nums.size();
        while(it <= n - 1){
            while(it + 1 <= n - 1 && nums[it + 1] == nums[it]){
                arg[it + 1] = arg[it] + 1;
                ++it;
            }
            ++ it;
        }
        int maxn = arg[0], ar = 0;
        for(int i = 1; i <= n - 1; ++i){
            if(arg[i] > maxn){
                maxn = arg[i];
                ar = i;
            }
        }
        return nums[ar];
    }
};
