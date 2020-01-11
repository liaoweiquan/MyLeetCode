// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
//
// Example 1:
//
//
//
// Input: 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.
//
//
// Example 2:
//
//
// Input: 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
//
// Note: You may assume that n is not less than 2 and not larger than 58.
//
//


class Solution {
private:
    vector<int>vec;
    int max3(int x, int y, int z){
        int r = x;
        if(y > r)
            r = y;
        if(z > r)
            r = z;
        return r;
    }
    int dp(int n){
        if(n == 1)
            return 1;
        if(vec[n] != -1)
            return vec[n];
        int ret = -1;
        for(int i = 1; i <= n - 1; ++i)
            ret = max3(ret, i * (n - i), i * dp(n -i));
        vec[n] = ret;
        return ret;
    }
public:
    int integerBreak(int n) {
        vec = vector<int>(n + 1, -1);
        return dp(n);
    }
};
