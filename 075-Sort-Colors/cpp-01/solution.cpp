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
        int zero = -1;
        int two = nums.size();
        for(int i = 0; i< two;){
            if(nums[i] == 1)
                ++ i;
            else if(nums[i] == 2)
                swap(nums[i],nums[--two]);
            else
                swap(nums[++zero],nums[i++]);
        }
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