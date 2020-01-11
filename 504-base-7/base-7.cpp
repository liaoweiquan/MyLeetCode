// Given an integer, return its base 7 string representation.
//
// Example 1:
//
// Input: 100
// Output: "202"
//
//
//
// Example 2:
//
// Input: -7
// Output: "-10"
//
//
//
// Note:
// The input will be in range of [-1e7, 1e7].
//


class Solution {
public:
    string convertToBase7(int num) {
    	if(!num) return "0";
        int flat = num;
        num = fabs(num);
        string str = "";
        vector<int> nums;
        while(num >= 7){
        	int d = num / 7;
        	int y = num % 7;
        	nums.push_back(y);
        	num = d;
        }
        if(num > 0)
        	nums.push_back(num);
        if(flat < 0)
        	str += "-";
        int n = nums.size();
        for(int i = n - 1; i >= 0; --i)
        	{
        		str += nums[i] + '0';
        	}
        return str;
    }
};
