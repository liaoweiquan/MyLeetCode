// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
//
// Example 2:
//
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        vector<int> vt;
        while(head){
            vt.push_back(head->val);
            head = head->next;
        }
        sort(vt.begin(),vt.end());
        ListNode * ptr = NULL;
        head = NULL;
        for(auto i: vt){
            //ptr = new ListNode(i);
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
};
