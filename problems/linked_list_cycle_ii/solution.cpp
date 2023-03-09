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
        ListNode * slow =head, *fast = head;
        if (!head || !head->next) return nullptr;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow ==fast) break;
        }
        if (slow==fast && fast){
            slow=head;
            while (slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }        
        return nullptr;
    }
};