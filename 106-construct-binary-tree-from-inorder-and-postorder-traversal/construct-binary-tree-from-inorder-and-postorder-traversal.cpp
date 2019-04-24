// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
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
    TreeNode* buildTreeWithIP(vector<int>& inorder, vector<int>& postorder, int istart, int iend, int postart, int poend){
        if(istart > iend || postart > poend) return nullptr;
        auto root = new TreeNode(postorder[poend]);
        int index = 0;
        for(index = istart; index <= iend; ++ index){
            if(inorder[index] == postorder[poend])
                break;
        }
        root->left = buildTreeWithIP(inorder, postorder, istart, index - 1, postart, postart + index - istart - 1);
        root->right = buildTreeWithIP(inorder, postorder, index + 1, iend, postart + index - istart, poend - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeWithIP(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
