/**
* Created by yangyangu
* 2018 / 07
*/
#include <iostream>
#include <vector>

using namespace std;

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

int main(){
	Solution solution;
	return 0;
}