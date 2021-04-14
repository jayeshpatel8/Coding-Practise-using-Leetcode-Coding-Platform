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
    ListNode* partition(ListNode* head, int x) {
        ListNode * h1,*h2, h,t;
        h.next=head;        
        h1=&h;
        h2=&t;
        if (!head || !head->next) return head;
        
        while (h1->next){
            if (h1->next->val < x) h1 = h1->next;
            else {
                h2->next=h1->next;
                h2=h2->next;
                h1->next=h1->next->next;
            }
        }
        h1->next= t.next;
        h2->next=0;
        return h.next;
    }
};