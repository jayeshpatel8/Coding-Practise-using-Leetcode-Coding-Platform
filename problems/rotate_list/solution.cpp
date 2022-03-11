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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int l = len(head);
        
        k = k % l;
        if (k == 0) return head;
        ListNode * h = head, *p;
        int i= l - k -1;
        while( i-- > 0){
            h=h->next;
        }
        p=h; h=h->next;
        p->next=0; p = h;
        while(h->next)
            h=h->next;
        h->next = head;
        return p;
    }
    int  len(ListNode * h){
        int ans=0;
        while(h)
            ans++,h=h->next;
        return ans;
    }
};