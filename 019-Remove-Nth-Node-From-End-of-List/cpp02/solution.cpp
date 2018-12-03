/**
* Created by yangyangu
* 2018 / 02
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) return NULL;
        ListNode *nhead = new ListNode(0);
        nhead->next = head;
        ListNode *p = nhead, *q = nhead;
        for(int i = 0; i < n + 1; ++i)
            q = q->next;
        while(q != NULL){
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
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
}
int main(){
	Solution solution;
	vector<int> nums = {1,2,3,4,5};
	ListNode * list = createList(nums);
	int n = 2;
	ListNode * res = solution.removeNthFromEnd(list,n);
	printList(res);
	return 0;
}