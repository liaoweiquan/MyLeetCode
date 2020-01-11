// Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
//
// Example :
//
//
// Input: root = [4,2,6,1,3,null,null]
// Output: 1
// Explanation:
// Note that root is a TreeNode object, not an array.
//
// The given tree [4,2,6,1,3,null,null] is represented by the following diagram:
//
//           4
//         /   \
//       2      6
//      / \    
//     1   3  
//
// while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
//
//
// Note:
//
//
// 	The size of the BST will be between 2 and 100.
// 	The BST is always valid, each node's value is an integer, and each node's value is different.
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
    int minDiffInBST(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> que;
        vector<int> vt;
        TreeNode* p = NULL;
        que.push(root);
        while(!que.empty()){
            p = que.front();
            que.pop();
            vt.push_back(p->val);
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
        sort(vt.begin(),vt.end());
        vector<int> dis(vt.size());
        for(int i = 0; i <= vt.size() - 1; ++i){
            if(i == 0)
                dis[i] = fabs(vt[i + 1] - vt[i]);
            else if(i == vt.size() - 1)
                dis[i] = fabs(vt[i - 1] - vt[i]);
            else{
                int l = fabs(vt[i - 1] - vt[i]);
                int r = fabs(vt[i + 1] - vt[i]);
                dis[i] = l < r ? l : r;
            }
        }
        int minx = dis[0];
        for(int n : dis)
            if(n < minx)
                minx = n;
        return minx;
    }
};
