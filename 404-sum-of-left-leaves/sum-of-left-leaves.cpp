// Find the sum of all left leaves in a given binary tree.
//
// Example:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> que;
        int res = 0;
        if(!root) return 0;
        
        if(root->left){
            TreeNode* p = root->left;
            if(!p->left&&!p->right)res += p->val;
            que.push(root->left);
        }
        if(root->right)
            que.push(root->right);
            
        while(!que.empty()){
            TreeNode* p = que.front();
            if(p->left){
                if(!p->left->left&&!p->left->right)
                    res += p->left->val;
                que.push(p->left);
            }
            if(p->right){
                que.push(p->right);
            }
            que.pop();
        }
        return res;
    }
};
