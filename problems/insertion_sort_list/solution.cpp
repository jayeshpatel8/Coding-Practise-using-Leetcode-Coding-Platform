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
    void swap(ListNode * h,ListNode * h2){
        int t = h->val;
        h->val = h2->val;
        h2->val=t;
    }
    ListNode* insertionSortList(ListNode* head) {
        
        if (!head || !head->next) return head;
        ListNode * cur=head, dummy;
        while(cur){
            if (cur->next && cur->val > cur ->next->val)
            {
                ListNode * before=&dummy, *next=cur->next;
                before->next=head;
                
                while (before->next->val < next->val)
                    before = before->next;
                
                cur->next = next->next;
                if (before->next == head)head = next;
                
                // Append the list
                next->next = before->next;
                before->next = next;
            }
            else
                cur= cur->next;
        }
        return head;
    }
};