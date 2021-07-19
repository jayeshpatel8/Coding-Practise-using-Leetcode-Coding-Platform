class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1 ) return head;
        ListNode* h = head;
        int len=0;
        while(h) len++ , h=h->next;
        len /=k;
        head = rev( h = head, k);
        len--;
        while(0 != len--)
        {
            ListNode *n = h->next;
            h->next = rev(n, k);
            h= n;
        }
        return head;
    }
    
    // NULL -> A -> B -> C
    //NULL <-A <-B <- C
    ListNode * rev(ListNode * h, int k){
        ListNode * prev = NULL, *cur=h;
        while (cur && k--){
            ListNode * n = cur->next;
            cur->next = prev;
            prev=cur;
            cur = n;
        }
        h->next = cur;
        return prev;
    }
};