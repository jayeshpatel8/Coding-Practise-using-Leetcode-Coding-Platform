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
        if (!head->next) return true;
        ListNode * fast , * slow ;
        fast=slow=head;
        
        while(fast && fast->next && fast->next->next){
            fast=fast->next->next;
            {
                
                slow = slow->next;
            }
        }
        slow = slow ->next;

        return isPalindrome(&head,&slow);
    }
    bool isPalindrome(ListNode** L, ListNode** R){
        if (*L==*R || !*R) return true;
        
        if (!isPalindrome(L, &(*R)->next)) return false;
        if ((*L)->val != (*R)->val) return false;
        *L=(*L)->next;
         return true;
    }
};