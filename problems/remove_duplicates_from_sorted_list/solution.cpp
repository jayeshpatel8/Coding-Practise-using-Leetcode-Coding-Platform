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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur=head;
        while(cur ){
            ListNode* n = cur->next;
            auto c = cur->val;
            while (n &&  c== n->val)
                n=n->next;
            cur->next=n;            
            cur=n;
        }
        return head;
    }
};