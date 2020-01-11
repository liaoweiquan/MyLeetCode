// A full binary tree is a binary tree where each node has exactly 0 or 2 children.
//
// Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.
//
// Each node of each tree in the answer must have node.val = 0.
//
// You may return the final list of trees in any order.
//
//  
//
// Example 1:
//
//
// Input: 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// Explanation:
//
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 20
//
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if(N == 1){
            res.push_back(new TreeNode(0));
            return res;
        }
        N -= 1;
        for(int i = 1; i < N; i += 2){
            vector<TreeNode *> resL = allPossibleFBT(i);
            vector<TreeNode *> resR = allPossibleFBT(N - i);
            for(auto nl: resL){
                for(auto nr: resR){
                    auto cur = new TreeNode(0);
                    cur->left = nl;
                    cur->right = nr;
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};
