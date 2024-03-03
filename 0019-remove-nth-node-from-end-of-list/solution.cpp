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
        auto * h =head, *t = head;
        while (n>0  ){
            h=h->next;
            n--;
        }
        if (!h) return head->next;
        while (h->next) h= h->next,t=t->next;
        t->next = t->next->next;
        return head;
    }
};
