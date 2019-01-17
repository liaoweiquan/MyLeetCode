// Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
// For example, given a 3-ary tree:
//
//  
//
//
//
//  
//
// We should return its level order traversal:
//
//
// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]
//
//
//  
//
// Note:
//
//
// 	The depth of the tree is at most 1000.
// 	The total number of nodes is at most 5000.
//
//


/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vt;
        if(!root) return vt;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            queue<Node*> p;
            vector<int> v;
            while(!q.empty()){
                Node * ptr = q.front();
                if(ptr){
                    v.push_back(ptr->val);
                    int n = ptr->children.size();
                    if(n > 0){
                        for(Node *k: ptr->children){
                            if(k)
                                p.push(k);
                        }
                    }
                }
                q.pop();
            }
            vt.push_back(v);
            while(!p.empty()){
                Node * ptr = p.front();
                if(ptr)
                    q.push(ptr);
                p.pop();
            }
            
        }
        return vt;
    }
};
