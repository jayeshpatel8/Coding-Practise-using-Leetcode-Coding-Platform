/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow=head, *fast=head;
   
    if (!head ||!head->next) return 0;
   
    while (fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if (fast && (fast->val == slow->val)){

            return true;
        }
    }
    return false;
}