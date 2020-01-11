// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> vts;
        if(!root) return vts;
        TreeNode* p;
        queue<TreeNode*> u;
        queue<TreeNode*> d;
        u.push(root);
        while(!u.empty()){
            vector<int> vt;
            while(!u.empty()){
                p = u.front();
                vt.push_back(p->val);
                u.pop();
                if(p->left) d.push(p->left);
                if(p->right) d.push(p->right);
            }
            vts.push_back(vt);
            while(!d.empty()){
                p = d.front();
                d.pop();
                u.push(p);
            }
        }
        vector<vector<int>> res(vts.rbegin(),vts.rend());
        return res;
    }
};
