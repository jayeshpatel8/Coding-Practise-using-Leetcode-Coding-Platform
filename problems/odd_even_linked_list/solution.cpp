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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        auto  *odd = head , *even=head->next;
        auto * ot = odd,* et = even;
        while (ot->next && et->next){
            ot->next = ot->next->next;
            ot= ot->next;
            et->next = et->next->next;
            et= et->next;
        }
        ot->next = even;
        return odd;
    }
};