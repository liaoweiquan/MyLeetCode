/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(),'0');

	    for(int i = num1.size() - 1; i >= 0; --i){
	        int c = 0;
	        for(int j = num2.size() - 1; j >= 0; --j){
	            int t = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + c;
	            sum[i + j + 1] = t % 10 +'0';
	            c = t / 10;
	        }
	        sum[i] += c;
	    }
	    size_t startpos = sum.find_first_not_of("0");
	    if(string::npos != startpos){
	        return sum.substr((startpos));
	    }
	    return "0";
    }
};

int main(){
	Solution solution;
	string num1 = "2", num2 = "3";
	string res = solution.multiply(num1, num2);
	cout << res << endl;
	return 0;
}