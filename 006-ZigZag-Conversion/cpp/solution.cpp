/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
	    int len = (int)s.length();
	    if(len == 0 || numRows < 2) return s;
	    
	    string ret = "";
	    int lag = 2 * numRows - 2;
	    for(int i = 0; i < numRows; ++i){
	        for(int j = i; j < len; j += lag){
	            ret+=s.at(j);
	            if(i > 0 && i < numRows - 1){
	                int t = j + lag - 2 * i;
	                if(t < len){  
	                    ret += s.at(t);
	                }
	            }
	            
	        }
	    }
	    return ret;
	}
};

int main(){
	Solution solution;
	string str = "PAYPALISHIRING";
	int numRows = 3;
	string res = solution.convert(str, numRows);
	cout << res << endl;
	return 0;
}