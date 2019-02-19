// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
// Assume a BST is defined as follows:
//
//
// 	The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// 	The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// 	Both the left and right subtrees must also be binary search trees.
//
//
//  
//
// For example:
// Given BST [1,null,2,2],
//
//
//    1
//     \
//      2
//     /
//    2
//
//
//  
//
// return [2].
//
// Note: If a tree has more than one mode, you can return them in any order.
//
// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
//


/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (38.63%)
 * Total Accepted:    48.5K
 * Total Submissions: 125.6K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
public:
    int cur, cnt = 0, maxn = 0;
    vector<int> res;
    void inorder(TreeNode* node){
        if(node == nullptr){
            return;
        }
        inorder(node->left);
        ++ cnt;
        if(node->val != cur){
            cur = node->val;
            cnt = 1;
        }
        if(cnt > maxn){
            maxn = cnt;
            res.clear();
            res.push_back(node->val);
        }else if(cnt == maxn){
            res.push_back(node->val);
        }
        inorder(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};

