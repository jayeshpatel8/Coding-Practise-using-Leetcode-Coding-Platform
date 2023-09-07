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
    ListNode* reverseBetween(ListNode* head, int left, int right, int cur=1) {
        if (!head) return head;
        if (right == cur) return head;
        auto *h = reverseBetween(head->next,left,right, cur+1);
        if (cur >= left){
            if (head->next){
                auto *t = head->next->next;
                head->next->next=head;
                head->next= t;
            }
            return h;
        }
        head->next = h;
        return head;
    }
};