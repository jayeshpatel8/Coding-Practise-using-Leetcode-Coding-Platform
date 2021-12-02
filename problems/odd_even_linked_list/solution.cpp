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
        ListNode* odd = head, *even, *t;
        if (!odd || !odd->next) return head;
        
        t = even = head->next;
        
        while(even){
            if (even->next){
                odd->next = even->next;
                odd=odd->next;
                even->next = even->next->next;
            }
            even = even->next;
        }
        odd->next = t;
        return head;
    }
};

/*
2  3 6 1 5 
*/