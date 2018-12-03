/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() -1;
        int water = 0;
        while(i < j){
            int h = min(height[i],height[j]);
            water = max(water, (j-i)*h);
            while(height[i] <= h && i < j) i++;
            while(height[j] <= h && i < j) j--;
        }
        return water;
    }
};

int main(){
	Solution solution;
	vector<int> height = {1,8,6,2,5,4,8,3,7};
	int res = solution.maxArea(height);
	cout << res << endl;
	return 0;
}