// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its level order traversal as:
//
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<pair<TreeNode*,int>> q;
        TreeNode * p = NULL; 
        q.push(make_pair(root,0));
        while(!q.empty()){
            p = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l == res.size()){
                res.push_back(vector<int>());
            }
            res[l].push_back(p->val);
            if(p->left)
                q.push(make_pair(p->left,l + 1));
            if(p->right)
                q.push(make_pair(p->right,l + 1));
        }
        
        return res;
    }
};
