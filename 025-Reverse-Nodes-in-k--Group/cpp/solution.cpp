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
private:
    ListNode* swapPairs(ListNode* head, ListNode* tail){
    ListNode * prev = tail;

    while(head != tail){
        ListNode* t = head->next;
        head->next = prev;
        prev = head;
        head = t;
    }

    return prev;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
	    for(int i = 1; i <= k; ++i){
	        if(cur == NULL) return head;
	        cur = cur->next;
	    }
	    ListNode* n_head = swapPairs(head, cur);
	    head->next = reverseKGroup(cur, k);
	    return n_head;
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
	vector<int> nums = {1, 2, 3, 4, 5};
	ListNode * list1 = createList(nums);
	int k = 2;
	ListNode * res1 = solution.reverseKGroup(list1, k);
	printList(res1);

	k = 3;
	ListNode * list2 = createList(nums);
	ListNode * res2 = solution.reverseKGroup(list2, k);
	printList(res2);
	return 0;
}