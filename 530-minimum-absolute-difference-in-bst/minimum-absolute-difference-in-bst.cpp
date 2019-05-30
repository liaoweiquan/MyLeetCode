// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
//
// Example:
//
//
// Input:
//
//    1
//     \
//      3
//     /
//    2
//
// Output:
// 1
//
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
//
//
//  
//
// Note: There are at least two nodes in this BST.


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
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        vector<int> num;
        queue<TreeNode*> que;
        TreeNode* p = NULL;
        que.push(root);
        while(!que.empty()){
            p = que.front();
            que.pop();
            num.push_back(p->val);
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
        sort(num.begin(),num.end());
        int n = num.size();
        vector<int> vt(n, 0);
        for(int i = 0; i <= n - 1; ++i){
            if(i == 0){
                vt[i] = fabs(num[i + 1] - num[i]);
            }
            else if(i == n - 1){
                vt[i] = fabs(num[i] - num[i - 1]);
            }
            else{
                int l = fabs(num[i - 1] - num[i]);
                int r = fabs(num[i + 1] - num[i]);
                vt[i] = l < r ? l : r;
            }
        }
        int minx = vt[0];
        for(int nm : vt){
            if(nm < minx)
                minx = nm;
        }
        return minx;
    }
};
