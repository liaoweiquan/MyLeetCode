// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
//
//
// Given 1->2->3->4, reorder it to 1->4->2->3.
//
// Example 2:
//
//
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        vector<ListNode*> list;
        while(head){
            list.push_back(head);
            head = head->next;
        }
        ListNode * ptr = NULL;
        int n = list.size();
        int lt = 0, gt = n - 1;
        while(lt < gt){
            if(!head){
                ptr = list[lt];
                ptr->next = list[gt];
                ptr->next->next = NULL;
                head = ptr;
                ptr = ptr->next;
                ++ lt;
                -- gt;
            }
            else{
                ptr->next = list[lt];
                ptr->next->next = list[gt];
                ptr->next->next->next = NULL;
                ptr = ptr->next->next;
                ++ lt;
                -- gt;
            }
        }
        if(lt == gt){
            ptr->next = list[gt];
            ptr->next->next = NULL;
        }
    }
};
