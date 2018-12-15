/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Class for binary tree
class BinaryTree{

private:
	TreeNode * root;
	TreeNode * createTree(vector<string>nums){
		int n = nums.size();
		vector<TreeNode*> nodes;
		for(auto num: nums){
			if(num != "NULL"){
				int re = str2int(num);
				TreeNode * node = new TreeNode(re);
				nodes.push_back(node);
			}
			else
				nodes.push_back(NULL);
		}
		if(n <= 0) return NULL;
		queue<TreeNode*> que;
		int i = 1;
		que.push(nodes[0]);
		while(!que.empty()){
			queue<TreeNode*> hq;
			while(!que.empty()){
				TreeNode * temp = que.front();
				que.pop();

				int l = i;
				if(l >= n) return nodes[0];
				else{
					temp->left = nodes[l];
					if(temp->left) hq.push(temp->left);
				}
				int r = l + 1;
				if(r >= n) return nodes[0];
				else{
					temp->right = nodes[r];
					if(temp->right) hq.push(temp->right);
				}
				i = r + 1;
			}
			while(!hq.empty()){
				TreeNode * temp = hq.front();
				hq.pop();
				que.push(temp);
			}
		}
		//
		return nodes[0];
	}
	int str2int(string str){
		return atoi(str.c_str());
	}

public:
	BinaryTree(TreeNode * root){
		this->root = root;
	}
	BinaryTree(){}
	TreeNode * getTree(vector<string>nums){
		TreeNode* tr = createTree(nums);
		this->root = tr;
		return tr;
	}
	void printTree(TreeNode* root){
		if(!root) return;
		queue<TreeNode*> que;
		que.push(root);
		while(!que.empty()){
			queue<TreeNode*> hq;

			while(!que.empty()){
				TreeNode * temp = que.front();
				que.pop();
				if(temp){
					cout << temp->val << " ";
					hq.push(temp->left);
					hq.push(temp->right);
				}
				else{
					cout << "NULL ";
				}
			}
			cout << endl;
			while(!hq.empty()){
				TreeNode * temp = hq.front();
				hq.pop();
				que.push(temp); 
			}
		}
	}

};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vt;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        
        while(p || !stk.empty()){
            while(p){
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            vt.push_back(p->val);
            p = p->right;
        }
        return vt;
    }
};

int main(){
	Solution solution;
	vector<string> nums = {"1","NULL","2","3"};
	BinaryTree binaryTree;
	TreeNode * root = binaryTree.getTree(nums);
	
	vector<int> res = solution.inorderTraversal(root);
	int n = res.size();
	for(int i = 0; i < n; ++i){
		cout << res[i];
		if(i < n - 1)
			cout << "->";
	}
	cout << endl;
	return 0;
}