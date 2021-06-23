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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     if (right == left) return head;
        
        ListNode * tail, h ,*h1,*prev,*curr;
        h.next = head;
        h1= &h;
        right -=left;
        while(--left) h1 = h1->next;
        tail = h1->next;
        //h1->next = rev(h1->next,right);
        prev=NULL;
        curr=tail;
        while(right--){
            ListNode *t = curr->next;
            curr->next=prev;
            prev=curr;
            curr = t;
        }
        tail->next = curr->next;
        curr->next = prev;
        h1->next = curr;
        return h.next;
    }
};