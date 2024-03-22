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
    bool isPalindrome(ListNode* head) {
        auto * slow = head, *fast=head;
        while (fast && fast->next) slow=slow->next, fast=fast->next->next;
        
        //reverse
        ListNode * prev = NULL, *next;
        while(slow){
            next = slow->next;
            slow->next=prev;
            prev = slow;
            slow=next;
        }
        fast=head;
        while ( prev){
            if (prev->val != fast->val) return false;
            prev= prev->next; fast=fast->next;
        }
        return true;
    }
};
