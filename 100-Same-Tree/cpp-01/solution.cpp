/**
* Created by yangyangu
* 2018 / 02
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) return (p == q);
        else return (p->val == q->val) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right));
    }
};

int main(){
	Solution solution;

	//test sample 1
	vector<string> nums1 = {"1","2","3"};
	vector<string> nums2 = {"1","2","3"};
	BinaryTree binaryTree;
	TreeNode * tree1 = binaryTree.getTree(nums1);
	TreeNode * tree2 = binaryTree.getTree(nums2);

	bool is = solution.isSameTree(tree1, tree2);
	if(is)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	//test sample 2
	vector<string> nums3 = {"1","2","1"};
	vector<string> nums4 = {"1","1","2"};
	TreeNode * tree3 = binaryTree.getTree(nums3);
	TreeNode * tree4 = binaryTree.getTree(nums4);

	is = solution.isSameTree(tree3, tree4);
	if(is)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}