// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (42.74%)
 * Total Accepted:    80.2K
 * Total Submissions: 187.5K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        string rn1(num1.rbegin(), num1.rend());
        string rn2(num2.rbegin(), num2.rend());
        vector<int> vec;
        int minlen = min(rn1.size(), rn2.size()), maxlen = max(rn1.size(), rn2.size());
        for(int i = 0; i < minlen; ++ i){
            int a = rn1[i] - '0', b = rn2[i] - '0';
            int t = a + b;
            if(t <= 9){
                if(i >= vec.size()){
                    vec.push_back(t);
                }else{
                    vec[i] += t;
                }
            }else{
                int d = t / 10;
                t %= 10;
                if(i >= vec.size()){
                    vec.push_back(t);
                }else{
                    vec[i] += t;
                }

                if(i + 1 >= vec.size()){
                    vec.push_back(d);
                }else{
                    vec[i + 1] += d;
                }
            }
        }
        if(maxlen > minlen){
            if(rn1.size() == maxlen){
                for(int i = minlen; i < maxlen; ++i){
                    int t = rn1[i] - '0';
                    if(i >= vec.size()){
                        vec.push_back(t);
                    }else{
                        vec[i] += t;
                    }
                }
            }else if(rn2.size() == maxlen){
                for(int i = minlen; i < maxlen; ++i){
                    int t = rn2[i] - '0';
                    if(i >= vec.size()){
                        vec.push_back(t);
                    }else{
                        vec[i] += t;
                    }
                }
            }
        }
        for(int i = 0 ; i < vec.size(); ++i){
            if(vec[i] > 9){
                int d = vec[i] / 10;
                vec[i] %= 10;
                if(i + 1 >= vec.size()){
                    vec.push_back(d);
                }else{
                    vec[i + 1] += d;
                }
            }
        }
        string res = "";
        for(auto i: vec){
            res += (i + '0');
        }
        string re(res.rbegin(), res.rend());
        return re;
    }
};

