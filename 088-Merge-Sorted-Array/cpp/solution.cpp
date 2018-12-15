/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while(j >= 0)
            nums1[k--] = i >=0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
};

int main(){
	Solution solution;
	vector<int> nums1 = {1,2,3,0,0,0};
	vector<int> nums2 = {2,5,6};
	int m = 3, n = 3;
	solution.merge(nums1, m, nums2, n);
	for(auto i: nums1)
		cout << i << " ";
	cout << endl;
	return 0;
}