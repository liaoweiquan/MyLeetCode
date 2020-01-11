// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
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
