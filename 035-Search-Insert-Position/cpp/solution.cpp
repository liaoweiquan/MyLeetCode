/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <vector>

using namespace std;

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

int main(){
	Solution solution;
	vector<int> nums = {1,3,5,6};
	int target = 5;
	int res = solution.searchInsert(nums, target);
	cout << res << endl;
	return 0;
}