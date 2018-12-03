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
	        else if(target > nums[mid]){
	            lo = mid + 1;
	        }
	        else hi = mid - 1;
	    }
    	return -1;
	}
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
	        return -1;
	    if(nums.size() == 1 && nums[0] == target)
	        return 0;
	    int p = -1;
	    for(int i = 1;i <= nums.size() - 1;++ i){
	        if(nums[i] < nums[i-1]){
	            p = i;
	            break;
	        }
	    }
	    int re = BinarySearch(nums, 0, p - 1, target);
	    if(re == -1){
	        re = BinarySearch(nums, p, nums.size() - 1, target);
	    }
	    return re;
    }
};
int main(){
	Solution solution;
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;
	int res = solution.search(nums, target);
	cout << res << endl;
	return 0;
}