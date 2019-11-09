/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    int c=0;
    struct ListNode* l3=0,*node=0,*p=0;
    while (l1 && l2)
    {
        {
        node = (struct ListNode * )malloc(sizeof(struct ListNode));
        int x = l1->val + l2->val+c;
        c= (x>9);node->val=x%10;
        node->next=0;
        if(p)
            p->next=node;
        }
        if (l3==0)
            l3=node;
        p=node;
        //node=node->next;
        l1=l1->next;l2=l2->next;
    }
    while (l1)
    {
        
        node = (struct ListNode * )malloc(sizeof(struct ListNode));
        int x = l1->val +c;
        c= (x>9);node->val=x%10;
        node->next=0;
        p->next=node;
        p=node;
        l1=l1->next;
    }
    while (l2)
    {
        
        node = (struct ListNode * )malloc(sizeof(struct ListNode));
        int x =  l2->val+c;
        c= (x>9);node->val=x%10;
        node->next=0;
         p->next=node;p=node;
        l2=l2->next;
    }        
    if(c)
    {
    node = (struct ListNode * )malloc(sizeof(struct ListNode));
    node->val = 1;
    node->next=0;
    if(p)
        p->next=node;
    }        
    return l3;    
}
