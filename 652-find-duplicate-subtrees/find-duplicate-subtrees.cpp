// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//
// Two trees are duplicate if they have the same structure with same node values.
//
// Example 1: 
//
//
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
//
//
// The following are two duplicate subtrees:
//
//
//       2
//      /
//     4
//
//
// and
//
//
//     4
//
// Therefore, you need to return above trees' root in the form of a list.


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
    unordered_map<string, vector<TreeNode*>> mpt;
    string dfs(TreeNode* node){
        if(!node)
            return "";
        string str = "(" + dfs(node->left) + to_string(node->val) + dfs(node->right) + ")";
        mpt[str].push_back(node);
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode *>res;
        dfs(root);
        for(auto it = mpt.begin(); it != mpt.end(); ++ it){
            if(it->second.size() > 1)
                res.push_back(it->second[0]);
        }
        return res;
    }
};
