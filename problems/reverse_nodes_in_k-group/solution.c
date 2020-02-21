/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* revl (struct ListNode* c, int k){
            
struct ListNode* prev=c,*cur=c->next;
    while(cur && --k)
    {
        struct ListNode* t = cur->next;
        cur->next= prev;
        prev= cur;
        cur=t;
    }
    
    c->next=cur;
    return prev;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k){

    if (!head || !head->next || k<=1) return head;
    struct ListNode* prev=NULL,*c=head;
    
    int len=0;
    while(c){ len++; c=c->next; }
    
    if (len < k) return head;
    c=head;head=NULL;
    while (c && len>=k)
    {
        if (!head){
            prev=c;
            head= revl(c,k);            
        }
        else{
            
            prev->next= revl(c,k);
            prev=c;
        }
        c=c->next;
        len -=k;
    }
   
    return head;
}

