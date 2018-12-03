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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
	    vector<int>::iterator it;
	    int len = 0;
	    sort(nums.begin(),nums.end());
	    for(it = nums.begin(); it != nums.end(); ++it){
	        ++ len;
	    }
	    sort(nums.begin(),nums.end());
	    for(int i = 0;i <= len-1; ++ i){
	        if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
	            int lo = i + 1, hi = len -1, sum = 0 - nums[i];
	            while(lo < hi){
	                if(nums[lo] + nums[hi] == sum){
	                    vector<int> vt;
	                    vt.push_back(nums[i]);
	                    vt.push_back(nums[lo]);
	                    vt.push_back(nums[hi]);
	                    v.push_back(vt);
	                    while(lo < hi && nums[lo] == nums[lo+1]) ++lo;
	                    while(lo < hi && nums[hi] == nums[hi-1]) --hi;
	                    ++lo;
	                    --hi;
	                }
	                else if(nums[lo] + nums[hi] < sum) ++lo;
	                else --hi;
	            }
	        }
	    }
	    return v;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> res = solution.threeSum(nums);
	for(auto i: res){
		for(auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}