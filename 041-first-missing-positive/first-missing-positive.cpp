// Given an unsorted integer array, find the smallest missing positive integer.
//
// Example 1:
//
//
// Input: [1,2,0]
// Output: 3
//
//
// Example 2:
//
//
// Input: [3,4,-1,1]
// Output: 2
//
//
// Example 3:
//
//
// Input: [7,8,9,11,12]
// Output: 1
//
//
// Note:
//
// Your algorithm should run in O(n) time and uses constant extra space.
//


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0) return 1;
        int re = 0;
        int maxn = nums[0];
        map<int,int> mpt;
        for(int n:nums){
        	mpt.insert(make_pair(n,1));
        	if(maxn < n) maxn = n;
        }
        for(int i = 1; ; ++i){
        	if(i > maxn) return i;
        	if(mpt[i] == 1)
        		continue;
        	else return i;
        }
    }
};
