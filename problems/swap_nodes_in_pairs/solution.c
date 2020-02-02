/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){

    if (!head) return head;
    struct ListNode* r=0,*prev=0;
    
    if (head && head->next)
    {
        struct ListNode* t = head->next->next;
        head->next->next = head;
        head=head->next;        
        head->next->next = swapPairs( t);
        if (!r) r = head;        
   }
    if (!r) r = head;
    
    return r;
}

