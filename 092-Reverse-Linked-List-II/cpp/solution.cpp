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
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode *pre = newhead;
        for(int i = 0 ; i < m - 1; ++i)
            pre = pre->next;
        ListNode *cur = pre->next;
        for(int i = 0; i < n - m;++i){
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return newhead->next;
        
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
	vector<int> nums = {1,2,3,4,5};
	int m = 2, n = 4;
	ListNode * list = createList(nums);
	ListNode * res = solution.reverseBetween(list, m, n);
	printList(res);
	return 0;
}