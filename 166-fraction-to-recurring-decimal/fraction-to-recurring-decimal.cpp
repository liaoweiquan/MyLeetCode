// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
// If the fractional part is repeating, enclose the repeating part in parentheses.
//
// Example 1:
//
//
// Input: numerator = 1, denominator = 2
// Output: "0.5"
//
//
// Example 2:
//
//
// Input: numerator = 2, denominator = 1
// Output: "2"
//
// Example 3:
//
//
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"
//
//


using ll = long long;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int s1 = numerator > 0 ? 1 : -1;
        int s2 = denominator > 0 ? 1 : -1;
        ll num = abs((ll)numerator);
        ll den = abs((ll)denominator);
        ll out = num / den;
        ll let = num % den;
        string res = "";

        if(s1 * s2 < 0 && num && den)
            res += "-";
        res += to_string(out);
        if(let == 0)
            return res;
        res += ".";
        unordered_map<ll, int> mpt;
        string tmp;
        int pos = 0;
        while(let){

            if(mpt.find(let) != mpt.end()){
                tmp.insert(mpt[let],"(");
                tmp += ")";
                break;
            }

            mpt[let] = pos++;
            tmp += to_string(let * 10 / den);
            let = let * 10 % den;
        }
        res += tmp;
        return res;
    }
};
