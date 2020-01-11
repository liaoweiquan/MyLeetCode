// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements that appear twice in this array.
//
// Could you do it without extra space and in O(n) runtime?
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [2,3]
//


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(!n)
            return res;
        sort(nums.begin(),nums.end());
        for(int i = 1; i < n; ++ i){
            if(nums[i - 1] == nums[i]){
                int tmp = nums[i];
                res.push_back(tmp);
                while(i + 1 < n && nums[i] == tmp) ++ i;
            }
        }
        return res;
    }
};
