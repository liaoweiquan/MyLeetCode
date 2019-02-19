// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
// Note: The length of path between two nodes is represented by the number of edges between them.
//
//
// Example 1:
//
//
//
//
// Input:
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
//
//
//
//
// Output:
//
// 2
//
//
//
//
// Example 2:
//
//
//
//
// Input:
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
//
//
//
//
// Output:
//
// 2
//
//
//
// Note:
// The given binary tree has not more than 10000 nodes.  The height of the tree is not more than 1000.
//


/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (33.13%)
 * Total Accepted:    48.9K
 * Total Submissions: 147.4K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * Note: The length of path between two nodes is represented by the number of
 * edges between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 
 * 
 * Output:
 * 
 * 2
 * 
 * 
 * 
 * Note:
 * The given binary tree has not more than 10000 nodes.  The height of the tree
 * is not more than 1000.
 * 
 */
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
private:
    int maxn;
    int dfs(TreeNode* node){
        int left = 0, right = 0;
        if(node->left){
            if(node->left->val == node->val){
                left += dfs(node->left) + 1;
            }else{
                left = 0;
                dfs(node->left);
            }
        }
        if(node->right){
            if(node->right->val == node->val){
                right += dfs(node->right) + 1;
            }else{
                right = 0;
                dfs(node->right);
            }
        }
        maxn = max(maxn, right + left);
        return max(left, right);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        maxn = 0;
        dfs(root);
        return maxn;
    }
};

