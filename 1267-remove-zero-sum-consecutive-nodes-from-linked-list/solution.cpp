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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode *> m;
        ListNode h ,* t = head;
        h.next = head;
        m[0]=&h;
        h.val = 0;
        int presum = 0;
        while (t){
            presum += t->val;
            if (m.count(presum)){
                auto * p = m[presum] , *p2=p->next;
                int s = presum;
                while (p2 != t){
                    s += p2->val;
                    m.erase(s);
                    p2=p2->next;
                }
                p->next = t->next;                 
            }
            else { m[presum]=t;;
            }
            t=t->next;
            
        }
        return h.next;
    }
};
// 1 6 7
