// Given a linked list, swap every two adjacent nodes and return its head.
//
// Example:
//
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Note:
//
//
// 	Your algorithm should use only constant extra space.
// 	You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
