// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr=new ListNode(0);
        ListNode* tail=ptr;
        
        int p=0,v1=0,v2=0;
        while(l1!=NULL||l2!=NULL){
            v1=v2=0;
            if(l1!=NULL){
                v1=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                v2=l2->val;
                l2=l2->next;
            }
            int t=v1+v2+p;
            ptr->next= new ListNode(t%10);
            p=t/10;
            ptr=ptr->next;
        }
        if(p==1){
            ptr->next= new  ListNode(1);
        }
        return tail->next;
    }
};
