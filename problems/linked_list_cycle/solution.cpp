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
    bool hasCycle(ListNode *head) {
        if (!head ) return false;
        ListNode * fast = head->next, *slow = head->next;
        if (fast) fast= fast->next;
        while (slow != fast && fast){
            slow= slow->next;
            if (fast->next) fast=fast->next->next;
            else fast=nullptr;
        }   
        return slow ==fast && fast;
    }
};