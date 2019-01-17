// Given a singly linked list, determine if it is a palindrome.
//
// Example 1:
//
//
// Input: 1->2
// Output: false
//
// Example 2:
//
//
// Input: 1->2->2->1
// Output: true
//
// Follow up:
// Could you do it in O(n) time and O(1) space?
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
    ListNode * reList(ListNode * head){
        if(!head || !head->next) return head;
        ListNode *prev = NULL, *cur = head, *next = NULL;
        while(cur->next){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        cur->next = prev;
        return cur;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode * slow = head, * fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reList(slow->next);
        slow = slow->next;
        ListNode * cur = head;
        while(slow){
            if(cur->val != slow->val)
                return false;
            cur = cur->next;
            slow = slow->next;
        }
        return true;
    }
};
