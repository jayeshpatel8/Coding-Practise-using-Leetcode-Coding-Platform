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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
     auto h =  head;
        while (h){            
            if (h->next)
            {
                auto a = h->val;
                 auto b = h->next->val;
                auto t = h->next;
                h->next = new ListNode (__gcd(a,b));
                h->next->next = t;
                h = t;                
            }
            else break;
        }   
        return head;
    }
};
