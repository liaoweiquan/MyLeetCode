// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//
// Example:
//
//
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
// Note:  
//
//
// 	1 is typically treated as an ugly number.
// 	n does not exceed 1690.
//


class Solution {
public:
    
    int nthUglyNumber(int n) {
        vector<int> arr(n,0);
        int idx2 = 0, idx3 = 0, idx5 = 0;
        int f2 = 2, f3 = 3, f5 = 5;
        arr[0] = 1;
        for(int i = 1; i < n; ++ i){
            int minx = min(f2, min(f3, f5));
            arr[i] = minx;
            if(f2 == minx)
                f2 = 2 * arr[++ idx2];
            if(f3 == minx)
                f3 = 3 * arr[++ idx3];
            if(f5 == minx)
                f5 = 5 * arr[++ idx5];
        }
        return arr[n - 1];
    }
};
