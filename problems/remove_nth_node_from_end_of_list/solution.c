/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
struct ListNode* node = head;
struct ListNode* head1 = head;
    int len=1;
    int n1=n;
    while(head->next && (n >0)){
        head=head->next;len++;n--;}
    while(head->next)
        head=head->next,node=node->next,len++;
           
    if (node->next && n==0)
    node->next= node->next->next;
    if (len==1 && n>0)
        return 0;
    else if (n1==len)
        head1=head1->next;
 
    return head1;
}

