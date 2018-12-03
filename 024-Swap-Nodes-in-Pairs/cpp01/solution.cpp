/**
* Created by yangyangu
* 2018 / 01
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
        if(head == NULL || head->next== NULL) return head;
	    ListNode *cur = NULL, *ltr = NULL, *ptr = NULL;
	    ltr = head;
	    cur = head->next;
	    
	    ptr = cur->next;
	    cur->next = ltr;
	    ltr->next = ptr;
	    
	    head = cur;
	    cur = ltr->next;
	    
	    
	    while(cur && cur->next){
	        ptr = cur->next->next;
	        ltr->next = cur->next;
	        cur->next->next = cur;
	        cur->next = ptr;
	        
	        ltr = cur;
	        cur = cur->next;
	    }

	    return head;
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