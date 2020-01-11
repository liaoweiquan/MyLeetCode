//
// Given two strings representing two complex numbers.
//
//
// You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
//
//
// Example 1:
//
// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
//
//
//
// Example 2:
//
// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
//
//
//
// Note:
//
// The input strings will not have extra blank.
// The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
//
//


class Solution {
public:
    vector<int> getNum(string s){
        int a = 0, b = 0;
        int i = 0, n = s.size();
        int fl = 1;
        while(i < n && s[i] != '+'){
            if(i == 0 && s[i] == '-'){
                fl = -1;
            }else{
                a = 10 * a + (s[i] - '0');
            }
            ++ i;
        }
        a *= fl;
        if(s[i] == '+') ++ i;
        if(s[i] == '-'){
            ++ i;
            fl = -1;
        }else
            fl = 1;
//        fl = s[i] == '-' ? -1 : 1;
//        ++ i;
        while(i < n && s[i] != 'i'){
            b = 10 * b + (s[i] - '0');
            ++ i;
        }
        b *= fl;
        vector<int> res(2,0);
        res[0] = a;
        res[1] = b;
        return res;
    }
    string complexNumberMultiply(string a, string b) {
        vector<int> res1 = getNum(a);
        vector<int> res2 = getNum(b);
        int num1 = (res1[0]* res2[0] - res1[1] * res2[1]);
        int num2 = (res1[0] * res2[1] + res1[1] * res2[0]);
        string res = to_string(num1) + "+" + to_string(num2) + "i";
        return res;
    }
};
