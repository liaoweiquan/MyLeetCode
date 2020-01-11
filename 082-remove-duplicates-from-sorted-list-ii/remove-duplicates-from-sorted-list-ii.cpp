// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
// Example 1:
//
//
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5
//
//
// Example 2:
//
//
// Input: 1->1->1->2->3
// Output: 2->3
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
