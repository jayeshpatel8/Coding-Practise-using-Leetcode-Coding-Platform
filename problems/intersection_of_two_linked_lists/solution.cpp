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
        int l1 = 0 ,l2 = 0;
        auto * h1 = headA;
        while (h1)
            l1++, h1= h1->next;
        h1 = headB;
        while (h1)
            l2++, h1= h1->next;
        auto *h2=headB;

        if (l1 > l2){
            h1= headA;
            int d = l1-l2;
            while (d--)
                h1=h1->next;
        }
        else{
            h1= headB;
            h2=headA;
            int d = l2-l1;
            while (d--)
                h1=h1->next;
        }
        while(h1){
            if (h1 == h2) return h1;
            h1 = h1->next,h2=h2->next;
        }
        return NULL;
    }
};