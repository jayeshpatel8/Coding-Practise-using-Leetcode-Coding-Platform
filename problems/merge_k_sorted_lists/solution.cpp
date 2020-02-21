/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode*  mergelist(ListNode *a, ListNode *b){
    ListNode *p,*h;
    if (b==NULL) return a;
    if (a==NULL) return b;
    
    if (a->val < b->val) {p= a;a=a->next;}
    else {p= b;b=b->next;};
    h=p;
    while (a && b){
        if (a->val < b->val) {p->next= a;a=a->next;}
        else {p->next= b;b=b->next;}
        p=p->next;        
    }
    while (a)
        {p->next= a;a=a->next;p=p->next;}
    while (b)
        {p->next= b;b=b->next;p=p->next;}    
    return h;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())return NULL;
        int size=lists.size();
        
        while (size > 1){
            int i=0;
            while(i*2+1 < size)
            {            
                 lists[i]  = mergelist(lists[i*2],lists[i*2+1]);
                i+=1;
            }
            if (size >2 && size%2) lists[i]=lists[i*2];
            size = size/2 + size%2;
           // lists.resize(size);
         //   printf("%d,", size);
        }
        return lists[0];
    }
};