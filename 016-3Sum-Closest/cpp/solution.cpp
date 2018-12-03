/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minx = nums[0] + nums[1] + nums[nums.size() - 1];
	    sort(nums.begin(),nums.end());
	    for(int i = 0;i <= nums.size() - 1;++ i){
	        int lo = i + 1, hi = nums.size() - 1;
	        while(lo < hi){
	            int sum = nums[i] + nums[lo] + nums[hi];
	            if(sum > target) --hi;
	            else ++lo;
	            if(abs(sum - target) < abs(minx - target))
	                minx = sum;
	        }
	    }
	    return minx;
    }
};
int main(){
	Solution solution;
	vector<int> nums = {-1, 2, 1, -4};
	int target = 1;
	int res = solution.threeSumClosest(nums, target);
	cout << res << endl;
	return 0;
}