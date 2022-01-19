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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode * slow = head->next, *fast = head->next->next;
        while (fast && fast->next && fast != slow) 
            fast =fast->next->next, slow = slow->next;
        if (fast != slow) return NULL;
        slow=head;
        while (fast != slow){
            fast=fast->next, slow= slow->next;
        }
        return slow;        
    }
};