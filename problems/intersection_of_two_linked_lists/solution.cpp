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
        if (!headA || !headB) return NULL;
        int l1=0,l2=0;
        ListNode * h1=headA, *h2= headB;
        while(h1){
            l1++;
            h1=h1->next;
        }
        while(h2){
            l2++;
            h2=h2->next;
        }        
        h1=headA;
        h2= headB;
        while (l1<l2){
            l2--;h2=h2->next;
        }
        while (l1>l2){
            l1--;h1=h1->next;
        }        
        while(h1){
            if(h1 ==h2) return h1;
            h1=h1->next;h2=h2->next;
        }
        return NULL;
    }
};