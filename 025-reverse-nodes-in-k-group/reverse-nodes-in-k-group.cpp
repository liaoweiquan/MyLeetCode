// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//
//
//
// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
//
//
// 	Only constant extra memory is allowed.
// 	You may not alter the values in the list's nodes, only nodes itself may be changed.
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
