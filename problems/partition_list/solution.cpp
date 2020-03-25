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
    ListNode* partition(ListNode* head, int x) {
        ListNode* c,*p;
        ListNode dummy;
        dummy.next=head;
        c=p=&dummy;
        while (c->next && c->next->val < x){p=p->next;        
        c=c->next;}
        if (c) c=c->next;
        while (c && c->next){
            ListNode* t = c->next;
            if (t->val < x){
                
                c->next=t->next;
                t->next=p->next;
                p->next=t;
                p=p->next;
      
            }
           else
            c=c->next;
        }
        return dummy.next;
    }
};