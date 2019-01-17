//
// Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. 
//
//
//
// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree. 
//
//
//
// If no such second minimum value exists, output -1 instead.
//
//
// Example 1:
//
// Input: 
//     2
//    / \
//   2   5
//      / \
//     5   7
//
// Output: 5
// Explanation: The smallest value is 2, the second smallest value is 5.
//
//
//
// Example 2:
//
// Input: 
//     2
//    / \
//   2   2
//
// Output: -1
// Explanation: The smallest value is 2, but there isn't any second smallest value.
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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root||(!root->left && !root->right)) return -1;
        queue<TreeNode*> que;
        que.push(root);
        vector<int> vt;
        TreeNode* p;
        while(!que.empty()){
            p = que.front();
            vt.push_back(p->val);
            que.pop();
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
        sort(vt.begin(),vt.end());
        int n = vt.size();
        int minx = vt[0];
        for(int i = 1; i <= n - 1; ++i)
            if(vt[i] > minx)
                return vt[i];
        return -1;
    }
};
