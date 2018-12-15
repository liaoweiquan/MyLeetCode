/**
* Created by yangyangu
* 2018 / 07
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int an = a.size(), bn = b.size();
        vector<int> strs;
        int i = an - 1, j = bn - 1;
        int c = 0;
        while(i >= 0 && j >= 0){
        	int na = a[i] - '0', nb = b[j] - '0';
        	strs.push_back((na + nb + c) % 2);
        	c = (na + nb + c) / 2;
        	--i;
        	--j;
        }
        if(i >= 0){
        	while(i >= 0){
        		int na = a[i] - '0';
        		strs.push_back((na + c) % 2);
        		c = (na + c) / 2;
        		--i;
        	}
        }
        else if(j >= 0){
        	while(j >= 0){
        		int nb = b[j] - '0';
        		strs.push_back((nb + c) % 2);
        		c = (nb + c) / 2;
        		--j;
        	}
        }
        if(c > 0){
        	strs.push_back(1);
        }
        
        string str = "";
        for(int k = strs.size() - 1; k >= 0; --k)
        	str += (strs[k] + '0');
        return str;
    }
};

int main(){
	Solution solution;
	string a = "11", b = "1";
	string res = solution.addBinary(a, b);
	cout << res << endl;
	return 0;
}