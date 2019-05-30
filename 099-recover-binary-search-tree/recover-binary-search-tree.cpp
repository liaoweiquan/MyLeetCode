// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Example 1:
//
//
// Input: [1,3,null,null,2]
//
//    1
//   /
//  3
//   \
//    2
//
// Output: [3,1,null,null,2]
//
//    3
//   /
//  1
//   \
//    2
//
//
// Example 2:
//
//
// Input: [3,1,4,null,null,2]
//
//   3
//  / \
// 1   4
//    /
//   2
//
// Output: [2,1,4,null,null,3]
//
//   2
//  / \
// 1   4
//    /
//   3
//
//
// Follow up:
//
//
// 	A solution using O(n) space is pretty straight forward.
// 	Could you devise a constant space solution?
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
    void inorder(vector<TreeNode*> & arr, TreeNode* node){
        if(!node){
            return;
        }
        inorder(arr, node->left);
        arr.push_back(node);
        inorder(arr, node->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        vector<TreeNode*> arr;
        inorder(arr, root);
        vector<int> list;
        for(auto &it: arr){
            if(it){
                list.push_back(it->val);
            }
        }
        sort(list.begin(), list.end());
        int cur = 0;
        for(auto &it: arr){
            if(it){
                it->val = list[cur ++];
            }
        }
    }
};
