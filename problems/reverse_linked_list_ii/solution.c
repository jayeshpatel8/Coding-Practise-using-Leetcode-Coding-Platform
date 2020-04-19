/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode dummy={.next=head};
    struct ListNode* ret = &dummy;
    if (m==n || !head) return head;
    n-=m;
    while (ret && ret->next && --m) ret=ret->next;
    
    if (ret){
        struct ListNode* t=ret->next,* prev=0;
        
        while(t && n--){
           struct ListNode* next = t->next;
            t->next=prev;
            prev=t;
            t=next;
        }
        
        if (ret->next) {ret->next->next=t->next;
                      ret->next=t; }
        if (t)t->next=prev;
        
    }
    return dummy.next;
}

