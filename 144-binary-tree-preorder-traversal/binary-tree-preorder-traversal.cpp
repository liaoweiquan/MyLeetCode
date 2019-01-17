// Given a binary tree, return the preorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,2,3]
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vt;
        stack<TreeNode*> stk;
        TreeNode *p = NULL;
        if(root) stk.push(root);
        while(!stk.empty()){
            p = stk.top();
            stk.pop();
            vt.push_back(p->val);
            if(p->right) stk.push(p->right);
            if(p->left) stk.push(p->left);
        }
        return vt;
    }
};
