/**
* Created by yangyangu
* 2017 / 11
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *nhead = new ListNode(0);
        nhead->next = head;
        ListNode *cur = head, *pre = nhead;
        while(cur){
            if(cur->next&&cur->val == cur->next->val){
                ListNode * p = cur->next;
                while(p->next&&p->next->val == cur->val) p = p->next;
                pre->next = p->next;
                cur = p->next;
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return nhead->next;
    }
};

// Create a list
ListNode* createList(vector<int> numsList){
	ListNode * head = nullptr, * ptr = nullptr;
	for(auto i : numsList){
		if(!head){
			head = new ListNode(i);
			ptr = head;
		}
		else{
			ptr->next = new ListNode(i);
			ptr = ptr->next;
		}
	}

	return head;
}

// Print the list
void printList(ListNode* list){
	while(list){
		cout << list->val << " ";
		list = list->next;
	}
	cout << endl;
}

int main(){
	Solution solution;
	vector<int> nums = {1,2,3,3,4,4,5};
	ListNode * list = createList(nums);
	ListNode * res = solution.deleteDuplicates(list);
	printList(res);
	return 0;
}