/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() == 0 && needle.size() == 0) return 0;
	    if(haystack.size()==0||haystack.size()<needle.size()) return -1;
	    if(needle.size()==0) return 0;
	        for(int i = 0 ;i <= haystack.size() - needle.size() ; ++ i){
	        if(needle[0] == haystack[i]){
	            int j = 1;
	            int k = i + 1;
	            while(j <= needle.size() -1){
	                if(needle[j]!= haystack[k]) break;
	                else{
	                    ++k;++j;
	                }
	            }
	            if(j ==needle.size()) return i;
	        }
	    }
	    return -1;
    }
};

int main(){
	Solution solution;
	string haystack = "hello", needle = "ll";
	int res = solution.strStr(haystack, needle);
	cout << res << endl;
	return 0;
}