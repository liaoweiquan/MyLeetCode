// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
// Example:
//
//
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> v;
        if(!root) return v;
        queue<pair<TreeNode*,int>> q;
        TreeNode * p = NULL; 
        q.push(make_pair(root,0));
        while(!q.empty()){
            p = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l == res.size()){
                res.push_back(vector<int>());
            }
            res[l].push_back(p->val);
            if(p->left)
                q.push(make_pair(p->left,l + 1));
            if(p->right)
                q.push(make_pair(p->right,l + 1));
        }
        
        //return res;
        
        for(int i = 0; i <= res.size() - 1; ++i){
            v.push_back(res[i][res[i].size() - 1]);
        }
        return v;
    }
};
