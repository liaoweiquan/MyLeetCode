// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
//
// Input: 123
// Output: 321
//
//
// Example 2:
//
//
// Input: -123
// Output: -321
//
//
// Example 3:
//
//
// Input: 120
// Output: 21
//
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//


class Solution {
public:
    int reverse(int x) {
        if(x>INT32_MAX||x<INT32_MIN) return 0;
    bool isNegative=false;
    if(x<0){
        x=-x;
        isNegative=true;
    }
    if(x>=1&&x<=9){
        if(isNegative) return -x;
        else return x;
    }
    int r=0;
    while(x>0){
        
        long temp=(long)r*10;
        if(temp>INT32_MAX) return 0;
        r=10*r+x%10;
        x/=10;
    }

    if(!isNegative)return r;
    else return -r;
    
}
};
