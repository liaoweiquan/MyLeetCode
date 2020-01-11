// We are given a binary tree (with root node root), a target node, and an integer value K.
//
// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
//
// Output: [7,4,1]
//
// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.
//
//
//
// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.
//
//
//  
//
// Note:
//
//
// 	The given tree is non-empty.
// 	Each node in the tree has unique values 0 <= node.val <= 500.
// 	The target node is a node in the tree.
// 	0 <= K <= 1000.
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> vt;
        if(!root) return vt;
        vector<vector<int>> memo(501,vector<int>(501, -1));
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode * p= stk.top();
            stk.pop();
            if(p->left){
                stk.push(p->left);
                memo[p->val][p->left->val] = memo[p->left->val][p->val] = 1;
            }
            if(p->right){
                stk.push(p->right);
                memo[p->val][p->right->val] = memo[p->right->val][p->val] = 1;
            }
        }
        for(int i = 0; i <= 500; ++ i){
            for(int j = 0; j <= 500; ++j){
                if(i == j)
                    memo[i][j] = 0;
                if(memo[i][j] != -1){
                    for(int k = 0; k <= 500 && k != i; ++k){
                        if(memo[j][k] != -1 && memo[i][k] == -1)
                            memo[i][k] = memo[i][j] + memo[j][k];
                            memo[k][i] = memo[i][k];
                    }
                }
            }
        }
        for(int k = 0; k <= 500; ++k){
            if(memo[target->val][k] == K)
                vt.push_back(k);
        }
        return vt;
    }
};
