// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q1, q2;
        TreeNode *p = NULL;
        
        q1.push(root);
        int l = 0;
        while(!q1.empty()){
            ++ l;
            vector<int> vt;
            while(!q1.empty()){
                p = q1.front();
                q1.pop();
                vt.push_back(p->val);
                if(p->left) q2.push(p->left);
                if(p->right) q2.push(p->right);
            }
            if(l % 2 != 0) res.push_back(vt);
            else res.push_back(vector<int>(vt.rbegin(),vt.rend()));
            while(!q2.empty()){
                p = q2.front();
                q2.pop();
                q1.push(p);
            }
        }
        
        return res;
    }
};
