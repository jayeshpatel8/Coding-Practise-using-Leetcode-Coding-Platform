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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0;
        ListNode * t = headA;
        while(t){
            t=t->next; l1++;
        }
        int l2=0;
        t = headB;
        while(t){
            t=t->next; l2++;
        }
        if (!l1 || !l2) return NULL;
        if(l1 > l2)
            while (l1-- !=l2)
            {
                headA=headA->next;
            }
        else if(l1 < l2)
            while (l1 != l2--)
            {
                headB=headB->next;
            }        
        while(headA != headB){
            headB=headB->next;headA=headA->next;
        }
        return headA;
    }
};