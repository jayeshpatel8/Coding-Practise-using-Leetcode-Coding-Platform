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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* slow=head, *fast=head;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow = slow->next;
        }
        
        ListNode * rev=slow->next, *prev=NULL;
        slow->next=NULL;
        while (rev){
            ListNode * t = rev->next;
            rev->next = prev;
            prev = rev;
            rev=t;
        }
        rev=prev;
        
        // Merge
        while(rev)
        {
            ListNode * t1 = head->next, *t2 = rev->next;
            head->next = rev;
            rev->next=t1;
            rev = t2;
            head=t1;            
        }
        return ;
    }
};