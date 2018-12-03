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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	    if(l1==NULL&&l2==NULL) return NULL;
	    if(l1==NULL) return l2;
	    if(l2==NULL) return l1;
	    ListNode * h, * cur;
	    if(l1->val>=l2->val){
	        h=l2;
	        l2 = l2->next;
	    }
	    else{
	        h = l1;
	        l1 = l1->next;
	    }
	    cur = h;
	    while(l1&&l2){
	        if(l1->val <= l2->val){
	            cur->next = l1;
	            cur = l1;
	            l1 = l1->next;
	        }
	        else{
	            cur->next = l2;
	            cur = l2;
	            l2 = l2->next;
	        }
	    }
	    if(l1){
	        cur->next = l1;
	    }
	    else if(l2){
	        cur->next = l2;
	    }
	    else cur->next = NULL;
	    return h;
	}
	ListNode* mergeKlists(vector<ListNode*>& lists, int start, int end){
	    if(start == end) return lists[start];
	    else if(start < end){
	        int mid = (end - start)/2 + start;
	        ListNode* left = mergeKlists(lists,start,mid);
	        ListNode* right = mergeKlists(lists,mid + 1, end);
	        return mergeTwoLists(left,right);
	    }
	}
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
	    if(lists.size()== 0) return NULL;
	    if(lists.size()==1) return lists[0];
	    return mergeKlists(lists,0,lists.size()-1);
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
	vector<ListNode *> lists;
	vector<int> nums1 = {1, 4, 5};
	vector<int> nums2 = {1, 3, 4};
	vector<int> nums3 = {2, 6};
	ListNode * list1 = createList(nums1);
	ListNode * list2 = createList(nums2);
	ListNode * list3 = createList(nums3);
	lists.push_back(list1);
	lists.push_back(list2);
	lists.push_back(list3);
	ListNode * res = solution.mergeKLists(lists);
	printList(res);
	return 0;
}