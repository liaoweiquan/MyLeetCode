/**
* Created by yangyangu
* 2018 / 07
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0) return 1;
        int re = 0;
        int maxn = nums[0];
        map<int,int> mpt;
        for(int n:nums){
        	mpt.insert(make_pair(n,1));
        	if(maxn < n) maxn = n;
        }
        for(int i = 1; ; ++i){
        	if(i > maxn) return i;
        	if(mpt[i] == 1)
        		continue;
        	else return i;
        }
    }
};
int main(){
	Solution solution;
	vector<int> nums = {1, 2, 0};
	int res = solution.firstMissingPositive(nums);
	cout << res << endl;
	return 0;
}