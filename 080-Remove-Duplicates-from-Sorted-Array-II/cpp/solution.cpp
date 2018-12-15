/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n : nums)
            if(i < 2 || n > nums[i - 2])
                nums[i++] = n;
        return i;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {1,1,1,2,2,3};
	int res = solution.removeDuplicates(nums);
	cout << res << endl;
	return 0;
}