// Given an n-ary tree, return the preorder traversal of its nodes' values.
//
// For example, given a 3-ary tree:
//
//  
//
//
//
//  
//
// Return its preorder traversal as: [1,3,5,6,2,4].
//
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
public:
    vector<int> preorder(Node* root) {
        
        stack<Node*> stk;
        stk.push(root);
        vector<int> vt;
        if(!root) return vt;
        while(!stk.empty()){
            Node * p = stk.top();
            stk.pop();
            vt.push_back(p->val);
            int n = p->children.size();
            if(n > 0){
                for(int i = n - 1; i >= 0; --i){
                    if(p)
                        stk.push(p->children[i]);
                }
            }
        }
        return vt;
    }
};
