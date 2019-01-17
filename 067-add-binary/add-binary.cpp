// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


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
