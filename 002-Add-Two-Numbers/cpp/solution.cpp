/**
* Created by yangyangu
* 2017 / 09
*/

#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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

int main(){
    Solution solution;
    ListNode *l1 = new ListNode(2);
    ListNode *ptr = l1;
    ptr->next = new ListNode(4);
    ptr = ptr->next;
    ptr->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    ptr = l2;
    ptr->next = new ListNode(6);
    ptr = ptr->next;
    ptr->next = new ListNode(4);

    ptr = solution.addTwoNumbers(l1,l2);

    while(ptr->next) cout << ptr->val << "->", ptr = ptr->next;
    cout << ptr->val << endl;

    return 0;
}