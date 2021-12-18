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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        int len = 0;
        ListNode * h =head;
        while(h)
            ++len, h = h->next;
        for ( int i=len - 1; i>=0; i--){
            ListNode * h =head;
            int j = 1;
            while (j++ < i) h = h->next;
            while (h->next && h->val > h->next->val) {
                swap(h->val , h->next->val);
                h=h->next;
            }
        }
        return head;
    }
};