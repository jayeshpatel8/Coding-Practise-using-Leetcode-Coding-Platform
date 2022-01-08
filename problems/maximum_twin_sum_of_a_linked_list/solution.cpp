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
        ListNode* slow = head,* fast = head;
        while(fast && fast->next){
            fast= fast->next->next;
            slow = slow->next;
        }
        ListNode * prev=NULL, *cur = slow , *next;
        while (cur){
            next = cur->next;
            cur->next = prev;
            prev= cur;
            cur= next;
        }
        int ans =0;
        while(prev){
            ans  = max(ans, prev->val + head->val);
            prev= prev->next; head = head->next;
        }
        return ans;
    }
};