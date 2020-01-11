// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
//
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
//
//  
//
// Example 2:
//
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False
//
//
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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        queue<TreeNode*> que;
        vector<int> vt;
        que.push(root);
        while(!que.empty()){
            TreeNode* r = que.front();
            vt.push_back(r->val);
            if(r->right) que.push(r->right);
            if(r->left) que.push(r->left);
            que.pop();
        }
        sort(vt.begin(),vt.end());
        int it = 0, gt = vt.size() - 1;
        for(int i = it; i <= gt; ++i){
            int j = gt;
            while(j- 1 >= i){
                if(vt[i] + vt[j] == k) return true;
                --j;
            }
        }
        return false;
    }
};
