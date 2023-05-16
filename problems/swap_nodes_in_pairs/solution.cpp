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
    ListNode* swapPairs(ListNode* head) {
        ListNode *h = head,*prev, dummy;
        prev=&dummy;
        dummy.next=head;
        while (h && h->next){
            prev->next = h->next;
            h->next = h->next->next;
            prev->next->next = h;
            prev = h;
            h=h->next;
        }
        return dummy.next;

    }
};