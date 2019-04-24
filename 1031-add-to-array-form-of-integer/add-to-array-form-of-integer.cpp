// For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].
//
// Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: A = [1,2,0,0], K = 34
// Output: [1,2,3,4]
// Explanation: 1200 + 34 = 1234
//
//
//
// Example 2:
//
//
// Input: A = [2,7,4], K = 181
// Output: [4,5,5]
// Explanation: 274 + 181 = 455
//
//
//
// Example 3:
//
//
// Input: A = [2,1,5], K = 806
// Output: [1,0,2,1]
// Explanation: 215 + 806 = 1021
//
//
//
// Example 4:
//
//
// Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
// Output: [1,0,0,0,0,0,0,0,0,0,0]
// Explanation: 9999999999 + 1 = 10000000000
//
//
//  
//
// Note：
//
//
// 	1 <= A.length <= 10000
// 	0 <= A[i] <= 9
// 	0 <= K <= 10000
// 	If A.length > 1, then A[0] != 0
//
//
//
//
//


class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> b;
        while(K){
            b.push_back(K % 10);
            K /= 10;
        }
        vector<int> a(A.rbegin(), A.rend());
        int len = min(A.size(), b.size());
        vector<int>r(max(A.size(), b.size()));
        int c = 0;
        for(int i = 0; i < len; ++ i){
            r[i] = b[i] + c + a[i];
            c = (b[i] + c + a[i]) / 10;
            r[i] %= 10;
        }
        if(a.size() > len && b.size() <= len){
            for(int i = len; i < a.size(); ++ i){
                r[i] = c + a[i];
                c = (c + a[i]) / 10;
                r[i] %= 10;
            }

        }else if(b.size() > len && a.size() <= len){
            for(int i = len; i < b.size(); ++ i){
                r[i] = c + b[i];
                c = (c + b[i]) / 10;
                r[i] %= 10;
            }
            
        }
        if(c){
                r.push_back(c);
            }
        vector<int> res(r.rbegin(), r.rend());
        return res;
    }
};
