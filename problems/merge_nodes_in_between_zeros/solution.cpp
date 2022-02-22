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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy; dummy.next=head;
        ListNode* h = &dummy, *cur=head->next;
        
        int sum=0;
        while (cur){
            if (cur->val == 0)
                h= h->next, h->val = sum, sum=0;
            else
                sum += cur->val;
            cur=cur->next;
        }
        h->next = NULL;
        return head;
    }
};