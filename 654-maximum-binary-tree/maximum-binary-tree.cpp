//
// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
//
// The root is the maximum number in the array. 
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number. 
//
//
//
//
// Construct the maximum tree by the given array and output the root node of this tree.
//
//
// Example 1:
//
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:
//
//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1
//
//
//
// Note:
//
// The size of the given array will be in the range [1,1000].
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
    TreeNode* buildTree(vector<int>& list, int l, int r){
        if(l - r > 0)
            return nullptr;
        if(l == r){
            return new TreeNode(list[l]);

        }
        // left
        int maxn = list[l], pos = l;
        for(int i = l; i <= r; ++ i){
           if(maxn < list[i]){
               maxn = list[i];
               pos = i;
           }
        }
        TreeNode * node = new TreeNode(maxn);
        node->left = buildTree(list, l, pos - 1);
        node->right = buildTree(list, pos + 1, r);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = buildTree(nums, 0, nums.size() - 1);
        return root;
    }
};
