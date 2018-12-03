/**
* Created by yangyangu
* 2018 / 01
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
       string s = "1";
	    if(n == 1 || n == 0) return s;
	    string q;
	    string str[10]={"0","1","2","3","4","5","6","7","8","9"};
	    while(-- n){
	        int i = 0, len = s.size();
	        q.clear();
	        while(i <= len - 1){
	            int cnt = 1;
	            while(i + 1 <= len - 1 && s[i] == s[i + 1]){
	                ++ i;
	                cnt ++;
	            }
	            string t;
	            q += str[cnt];
	            q += s[i];
	            ++ i;
	        }
	        s.clear();
	        s = q;
	    }
	    return s;
    }
};

int main(){
	Solution solution;
	int n = 5;
	string res = solution.countAndSay(n);
	cout << res << endl;
	return 0;
}