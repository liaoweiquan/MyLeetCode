// Reverse a singly linked list.
//
// Example:
//
//
// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL
//
//
// Follow up:
//
// A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* pHead) {
        ListNode * cur = pHead, * next = nullptr, * prev = nullptr;
        if(cur == nullptr) return cur;
        while(cur->next){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        cur->next = prev;
        return cur;
    }
};
