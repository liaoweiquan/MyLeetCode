// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
// Example:
//
//
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
//


class Solution {
public:
    int numTrees(int n) {
        vector<int> vec(n + 1, 0);
        vec[0] = 1;
        return help(n, vec);
    }
    int help(int n, vector<int> &vec){
        if(vec[n] != 0) return vec[n];
        for(int i = 1; i <= n; ++ i){
            vec[n] += help(i - 1, vec) * help(n - i, vec);
        }
        return vec[n];
    }
};
