/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
        	return 0;
	    int n = 1;
	    for(int i = 1;i <= nums.size()-1; ++i){
	        if(nums[i] != nums[i-1]){
	            nums[n] = nums[i];
	            ++n;
	        }
	    }
	    return n;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
	int res = solution.removeDuplicates(nums);
	cout << res << endl;
	return 0;
}