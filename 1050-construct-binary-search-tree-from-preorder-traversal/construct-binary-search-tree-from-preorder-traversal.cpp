// Return the root node of a binary search tree that matches the given preorder traversal.
//
// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
//
//  
//
// Example 1:
//
//
// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
//
//
//
//  
//
// Note: 
//
//
// 	1 <= preorder.length <= 100
// 	The values of preorder are distinct.
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
    TreeNode* buildTree(vector<int >pre,vector<int >in){
        int n=pre.size();
        if(n==0)
            return NULL;
        vector<int >pre_left,pre_right,in_left,in_right;
        int a=pre[0];
        TreeNode *root = new TreeNode(a);
        int i;
        for(i=0;i<pre.size();i++)
            if(a==in[i])
                break;
        for(int j=0;j<i;j++){
            pre_left.push_back(pre[j+1]);    
            in_left.push_back(in[j]);
        }
        for(int j=i+1;j<n;j++){
            pre_right.push_back(pre[j]);
            in_right.push_back(in[j]);
        }
        root->left=buildTree(pre_left,in_left);
        root->right=buildTree(pre_right,in_right);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        return buildTree(preorder,inorder);
    }
};
