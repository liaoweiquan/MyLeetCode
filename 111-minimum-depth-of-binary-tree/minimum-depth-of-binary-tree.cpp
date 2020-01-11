// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given binary tree [3,9,20,null,null,15,7],
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        int dep = 0;
        int rd = 0;
        int ld = 0;
        if(root == NULL)return dep;
        if(root->left == NULL && root->right == NULL) return 1;
        if(root->left)
            ld = minDepth(root->left) + 1;
        if(root->right)
            rd = minDepth(root->right) + 1;
        if(rd == 0)
            dep = ld;
        else if(ld == 0)
            dep = rd;
        else
            dep = ld < rd ? ld : rd;
        return dep;
        
    }
};
