// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
// Example:
//
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
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
    TreeNode* BinaryBuild(vector<int>& nums, int lo, int hi){
        if(lo > hi) return NULL;
        
        int mid = (hi + lo) / 2;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = BinaryBuild(nums, lo, mid - 1);
        head->right = BinaryBuild(nums, mid + 1, hi);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        TreeNode * head = BinaryBuild(nums, 0, nums.size() - 1);
        return head;
    }
};
