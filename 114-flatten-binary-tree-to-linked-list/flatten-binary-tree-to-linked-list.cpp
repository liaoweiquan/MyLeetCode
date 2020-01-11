// Given a binary tree, flatten it to a linked list in-place.
//
// For example, given the following tree:
//
//
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
//
//
// The flattened tree should look like:
//
//
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6
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
    vector<TreeNode*> list;
    void dfs(TreeNode *node){
        if(!node)
            return;
        list.push_back(node);
        if(node->left)
            dfs(node->left);
        if(node->right)
            dfs(node->right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        if(list.empty() || list.size() == 1)
            return;
        for(int i = 0; i < list.size() - 1; ++ i){
            list[i]->left = nullptr;
            list[i]->right = list[i + 1];
        }
        list[list.size() - 1]->left = nullptr;
        list[list.size() - 1]->right = nullptr;
    }
};
