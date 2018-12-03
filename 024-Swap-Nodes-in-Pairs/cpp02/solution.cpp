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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *nhead = new ListNode(0);
        nhead->next = head;
        ListNode *p = nhead;
        while(p->next&&p->next->next){
            ListNode *n1 = p->next, *n2 = n1->next;
            ListNode *next = n2->next;
            n2->next = n1;
            n1->next = next;
            p->next = n2;
            p = n1;
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
}

int main(){
	Solution solution;
	vector<int> nums = {1,2,3,4};
	ListNode * list = createList(nums);
	ListNode * res = solution.swapPairs(list);
	printList(res);
	return 0;
}