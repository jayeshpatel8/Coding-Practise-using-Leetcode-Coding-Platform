/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
     int len = 0;
        ListNode* h = head;
        while(h)
            h=h->next,len++;
        return sort(head,len);
    }
    ListNode * sort(ListNode * h, int l){
        if (l<=2){
            if (l<2) return h;
            if (h->next && h->val > h->next->val)
                swap(h->val , h->next->val);
           
            return h;
        }
        
        int m = l/2;
        auto h1=h;
        
        int cnt=m-1;
        while (cnt--)
            h=h->next;
        auto t = h->next;
        h->next=NULL;
        auto s1 = sort(h1,m);
        auto s2 = sort(t,l-m);
        //merge s1 , s2
        return merge(s1,s2);
    }
    ListNode * merge(ListNode * s1, ListNode * s2){
        ListNode dummy, * s = &dummy;
        
        while (s1 && s2){
            if (s1->val > s2->val)
                s->next = s2, s2=s2->next;
            else
                s->next = s1, s1=s1->next;            
            s=s->next;
        }
        while(s1)
            s->next = s1, s1=s1->next,s=s->next;
        while(s2)
            s->next = s2, s2=s2->next,s=s->next;
        s->next=NULL;
        return dummy.next;
    }
};