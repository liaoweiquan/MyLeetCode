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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0),right(0);
        ListNode *l = &left, *r = &right;
        ListNode *cur = head;
        while(cur){
            ListNode* & re = cur->val < x ? l : r;
            re->next = cur;
            re = re->next;
            
            cur = cur->next;
        }
        l->next = right.next;
        r->next = NULL;
        return left.next;
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
	vector<int> nums = {1,4,3,2,5,2};
	int x = 3;
	ListNode* list = createList(nums);
	ListNode* res = solution.partition(list, x);
	printList(res);
	return 0;
}