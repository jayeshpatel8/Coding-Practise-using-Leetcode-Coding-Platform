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
    ListNode* rotateRight(ListNode* head, int k) {
                
        ListNode* h= head, * end=head;
        int len=1;
        if (!head || !head->next) return head;
        while(end->next)len++, end=end->next;
        k %=len;
        if (!k) return head;
        h= head;

        len =len - k;
        cout << len;
        while (--len )
            h=h->next;
    
        end->next=head;
        head=h->next;
        h->next=NULL;
        return head;
    }
};