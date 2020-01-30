/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* new ,*t;
    
    if (!l1)
        return l2;
    if (!l2)
        return l1;        
    if (l1->val < l2->val){ 
        new = l1;
        l1=l1->next;
    }else {
        new=l2;
        l2=l2->next;
    }
    t=new;
    while (l1 && l2){
        if (l1->val < l2->val ){
            t->next = l1;l1=l1->next;
        }else{
            t->next = l2;l2=l2->next;
        }
        t=t->next;
    }
    if(!l1)
        t->next=l2;
    else if (!l2)
        t->next=l1;
    return new;
        
}

