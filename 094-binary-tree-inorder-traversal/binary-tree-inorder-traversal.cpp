// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,3,2]
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vt;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        
        while(p || !stk.empty()){
            while(p){
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            vt.push_back(p->val);
            p = p->right;
        }
        return vt;
    }
};
