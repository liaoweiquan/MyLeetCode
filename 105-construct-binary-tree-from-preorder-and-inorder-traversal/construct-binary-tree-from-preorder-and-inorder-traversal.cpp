// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    TreeNode* buildTreeWithPI(vector<int> & preorder, vector<int> & inorder, int pstart, int pend, int istart, int iend){
        if(pstart > pend || istart > iend) return nullptr;
        auto root = new TreeNode(preorder[pstart]);
        int index, n = preorder.size();
        for(index = 0; index < n; ++ index){
            if(inorder[index] == preorder[pstart])
                break;
        }
        root->left = buildTreeWithPI(preorder, inorder, pstart + 1, pstart + index - istart, istart, index - 1);
        root->right = buildTreeWithPI(preorder, inorder, pstart + index - istart + 1,pend,index + 1, iend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeWithPI(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
