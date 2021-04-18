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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if (!head ) return head;
        ListNode * h ,*h2,d;
        d.next=head;
        h=h2=&d;
        while(n--) h=h->next;
        while(h->next){ h=h->next;h2=h2->next;}
                        
        h2->next = h2->next->next;
        return d.next;
    }
};