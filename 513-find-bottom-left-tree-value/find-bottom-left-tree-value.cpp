//
// Given a binary tree, find the leftmost value in the last row of the tree. 
//
//
// Example 1:
//
// Input:
//
//     2
//    / \
//   1   3
//
// Output:
// 1
//
//
//
//   Example 2: 
//
// Input:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
//
// Output:
// 7
//
//
//
// Note:
// You may assume the tree (i.e., the given root node) is not NULL.
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
    void dfs(vector<int>& vec,TreeNode *node, int level){
        if(!node){
            return;
        }
        if(level == vec.size()){
            vec.push_back(node->val);
        }else{
            vec[level] = node->val;
        }
        dfs(vec, node->right, level + 1);
        dfs(vec, node->left, level + 1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> vec;
        dfs(vec, root, 0);
        return vec[vec.size() - 1];
    }
};
