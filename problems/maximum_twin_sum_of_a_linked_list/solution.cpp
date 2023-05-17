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
    int pairSum(ListNode* head) {
        int len =0 ,ans = 0;
        auto *h = head;
        while (h) h=h->next->next, len++;
        
        ListNode * prev=nullptr , *cur = head, *next;
        while (len--){
            next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }   
        while (cur){
            ans= max(ans, cur->val + prev->val);
            cur=cur->next;
            prev=prev->next;
        }
        return ans;
    }
};