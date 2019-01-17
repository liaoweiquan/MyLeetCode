// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
//
//
// Return:
//
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
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
private:
    void pathSum(TreeNode* node, vector<int>& vt,int sum){
        if(!node->left && !node->right){
            if(node->val == sum){
                vt.push_back(node->val);
                res.push_back(vt);
                vt.pop_back();
            }
            return;
        }
        vt.push_back(node->val);
        if(node->left){
            
            pathSum(node->left, vt, sum - node->val);
            
        }
        if(node->right){
            pathSum(node->right, vt, sum - node->val);
        }
        vt.pop_back();
    }
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        if(!root)
            return res;
        if(!root->left && !root->right ){
            if(root->val == sum)
                res.push_back(vector<int>(1,root->val));
            return res;
        }
        vector<int> vt;
        //vt.push_back(root->val);
        pathSum(root, vt, sum);
        
        return res;
    }
};
