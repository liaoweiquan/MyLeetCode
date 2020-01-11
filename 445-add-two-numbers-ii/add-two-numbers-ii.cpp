// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//
//
//
// Example:
//
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7
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
        stack<int> stk1, stk2;
        while(l1){
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            stk2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode * root = new ListNode(0);
        while(!stk1.empty() || !stk2.empty()){
            if(!stk1.empty()){
                sum += stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()){
                sum += stk2.top();
                stk2.pop();
            }
            root->val = sum % 10;
            ListNode * node = new ListNode(sum / 10);
            sum /= 10;
            node->next = root;
            root = node;
        }
        return root->val != 0 ? root : root->next;
    }
};
