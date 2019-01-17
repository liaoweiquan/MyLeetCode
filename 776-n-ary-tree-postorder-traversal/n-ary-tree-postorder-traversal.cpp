// Given an n-ary tree, return the postorder traversal of its nodes' values.
//
// For example, given a 3-ary tree:
//
//  
//
//
//
//  
//
// Return its postorder traversal as: [5,6,3,2,4,1].
//  
//
// Note:
//
// Recursive solution is trivial, could you do it iteratively?
//


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private:
    vector<int> vt;
    void helper(Node* root){
        if(root && root->children.size() > 0){
            for(Node* k: root->children)
                helper(k);
        }
        if(root)
            vt.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        helper(root);
        return vt;
    }
};
