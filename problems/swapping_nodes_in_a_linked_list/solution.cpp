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
    ListNode* swapNodes(ListNode* head, int k) {
        auto * h = head ,*h2 = head ,*h1=head;
        for (int i=1; i<k ; i++) h=h->next;
        h1 = h;
        while (h->next) h=h->next, h2=h2->next;
        swap(h1->val,h2->val);
        return head;
    }
};