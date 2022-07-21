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
        if (right==left) return head;
        
        ListNode  *h, ans;
        h = &ans;
        h->next = head;
        right -=left;
        while (--left) h = h->next ;
        
        ListNode *prev =h->next, *tail = h->next ,*cur = h,*next;
        h = prev->next;
        
        while (right--){
            next  = h->next;
            h->next = prev;
            prev = h;
            h = next;
        }

        cur->next= prev; 
        tail->next= next;
        return ans.next;
            
        return ans.next;
    }
};