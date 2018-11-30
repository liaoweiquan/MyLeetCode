/**
* Created by yangyangu
* 2017 / 09
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int>res;
        for(int i=0;i<nums.size();++i){
            m[nums[i]]=i;
        }
        for(int i=0;i<nums.size();++i){
            int t=target-nums[i];
            if(m.count(t)&&m[t]!=i){
                res.push_back(i);
                res.push_back(m[t]);
                break;
            }
        }
        return res;
    }
};

int main(){
	Solution solution;
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	vector<int> res = solution.twoSum(nums, target);
	for(auto n : res)
		cout << n << endl;
	return 0;
}