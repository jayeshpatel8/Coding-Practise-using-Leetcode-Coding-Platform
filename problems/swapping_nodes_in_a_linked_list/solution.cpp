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
        ListNode dummy;
        dummy.next = head;
        auto * slow =&dummy , *fast =&dummy;
        while(k--)
            fast=fast->next;
        auto *node1 =fast;
        while(fast)
            fast=fast->next, slow=slow->next;
        swap(slow->val,node1->val);
        return head;
    }
};