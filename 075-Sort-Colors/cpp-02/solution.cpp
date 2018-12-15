/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> vt(3,0);
        for(int n: nums)
            ++ vt[n];
        int index = 0;
        for(int i = 0; i < vt[0]; ++i)
            nums[index++] = 0;
        for(int i = 0; i < vt[1]; ++i)
            nums[index++] = 1;
        for(int i = 0; i < vt[2]; ++i)
            nums[index++] = 2;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {2,0,2,1,1,0};
	solution.sortColors(nums);
	for(auto i: nums)
		cout << i << " ";
	cout << endl;
	return 0;
}