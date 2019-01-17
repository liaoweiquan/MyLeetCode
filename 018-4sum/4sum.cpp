// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for(int i = 0;i <= len-1; ++ i){
        if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
            int j = len - 1;
            while(i < j){
                int it = i + 1, jt = j - 1;
                int sum = target - nums[i] - nums[j];
                while(it < jt){
                    if(nums[it] + nums[jt] == sum){
                        vector<int> vt;
                        vt.push_back(nums[i]);
                        vt.push_back(nums[it]);
                        vt.push_back(nums[jt]);
                        vt.push_back(nums[j]);
                        v.push_back(vt);

                        while(it < jt && nums[it] == nums[it + 1]) ++it;
                        while(it < jt && nums[jt - 1] == nums[jt]) --jt;
                        ++it;
                        --jt;
                    }
                    else if(nums[it] + nums[jt] < sum) ++it;
                    else --jt;
                }
                while(i < j && nums[j-1] == nums[j]) --j;
                --j;
            }

        }
    }

    return v;
    }
};
