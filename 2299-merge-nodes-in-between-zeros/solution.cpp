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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * h =  head, *t,n;
        t=&n;

        while (h){
            int s = 0;
            if(h && h->val == 0) { 
                h= h->next;
                while (h&& h->val !=0 )
                    s +=h->val, h=h->next;
                if (s){
                    t->next = new ListNode(s);
                    t=t->next;
                }
            }
        }
        return n.next;
    }
};
