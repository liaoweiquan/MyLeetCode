// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
//
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//
// Could you do this in O(n) runtime?
//
// Example:
//
//
// Input: [3, 10, 5, 25, 2, 8]
//
// Output: 28
//
// Explanation: The maximum result is 5 ^ 25 = 28.
//
//
//  
//


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxn = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            for(int j = i + 1; j < n; ++ j){
                maxn = max(maxn, nums[i] ^ nums[j]);
            }
        }
        return maxn;
    }
};
