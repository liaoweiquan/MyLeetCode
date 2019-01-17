// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//
//


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	int n = digits.size();
    	digits[n - 1] += 1;
        for(int i = n - 1; i >= 1; --i){
        	if(digits[i] >= 10){
        		digits[i] -= 10;
        		digits[i - 1] += 1;
        	}
        }
        if(digits[0] <= 9)
        	return digits;
        else{
        	int c = digits[0] / 10;
        	digits[0] %= 10;
        	vector<int> vec;
        	vec.push_back(c);
        	for(int num: digits){
        		vec.push_back(num);
        	}
        	return vec;
        }
    }
};
