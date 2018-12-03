/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x){
	    int xt = x;
	    int r = 0;
	    while(x != 0){
	        r = r * 10 + x % 10;
	        x /= 10;
	    }
	    if(r != xt) return false;
	    if(xt < 0) return false;
	    return true;
	}
};

int main(){
	Solution solution;
	int x = 121;
	if(solution.isPalindrome(x))
		cout << "true" << endl;
	else cout << "false" << endl;
	return 0;
}