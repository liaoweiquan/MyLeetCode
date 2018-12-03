/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
	    if(nums.size() == 0 || (nums.size() == 1 && nums[0] != target)){
	        v.push_back(-1);
	        v.push_back(-1);
	        return v;
	    }
	    int lo = 0, hi = nums.size() - 1;
	    while(lo <= hi){
	        int mid = lo + (hi - lo) / 2;
	        if(nums[mid] == target){
	            int r = mid;
	            while(r+1 <= nums.size() - 1 && nums[r+1] == target) ++r;
	            int l = mid;
	            while(l-1 >= 0 && nums[l-1] == target) --l;
	            v.push_back(l);
	            v.push_back(r);
	            return v;
	        }
	        else if (nums[mid] > target){
	            hi = mid - 1;
	        }
	        else{
	            lo = mid + 1;
	        }
	    }
	    v.push_back(-1);
	    v.push_back(-1);
	    return v;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {5,7,7,8,8,10};
	int target = 8;
	vector<int> res = solution.searchRange(nums, target);
	for(auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}