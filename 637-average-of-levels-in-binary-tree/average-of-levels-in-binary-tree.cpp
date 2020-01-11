// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
//
// Example 1:
//
// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
//
//
//
// Note:
//
// The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vt;
        queue<TreeNode*> que;
        queue<TreeNode*> cur;
        TreeNode* r;
        que.push(root);
        int cnt = 0;
        while(!que.empty()){
            double n = 0;
            long long sum = 0;
            int count = 0;
            //cur.clear();
            while(!que.empty()){
                r = que.front();
                sum += r->val;
                if(r->left) cur.push(r->left);
                if(r->right) cur.push(r->right);
                ++ count;
                que.pop();
            }
            n = (double)sum/count;
            vt.push_back(n);
            
            while(!cur.empty()){
                r = cur.front();
                que.push(r);
                cur.pop();
            }
        }
        
        return vt;
    }
};
