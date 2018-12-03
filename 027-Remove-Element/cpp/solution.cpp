/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)
	        return 0;
	    int n = 0;
	    for(int i = 0;i <= nums.size()-1; ++i){
	        if(nums[i] != val){
	            nums[n++] = nums[i];
	        }
	    }
	    return n;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {0,1,2,2,3,0,4,2};
	int val = 2;
	int res = solution.removeElement(nums, val);
	cout << res << endl;
	return 0;
}