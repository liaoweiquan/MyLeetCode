// Given a list of non negative integers, arrange them such that they form the largest number.
//
// Example 1:
//
//
// Input: [10,2]
// Output: "210"
//
// Example 2:
//
//
// Input: [3,30,34,5,9]
// Output: "9534330"
//
//
// Note: The result may be very large, so you need to return a string instead of an integer.
//


bool cmp(int a, int b){
    string s_a = to_string(a), s_b = to_string(b);
    int l1 = s_a.length(), l2 = s_b.length();
    if(l1 == l2)
        return a > b;
    return s_a + s_b > s_b + s_a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res;
        bool zero = true;
        for(auto & num: nums){
            if(num == 0 && zero)
                continue;
            if(num != 0)
                zero = false;
            res += to_string(num);
        }
        if(res == "")
            return "0";
        return res;
    }
};
