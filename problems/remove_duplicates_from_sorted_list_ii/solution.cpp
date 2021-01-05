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
    ListNode* deleteDuplicates(ListNode* t) {
        if (!t || !t->next) return t;
        ListNode dummy,*p;
        p=&dummy; 
        while(t && t->next){
             if(t->val != t->next->val){
                p->next = t;
                t=t->next;
            }
            else{
                int v = t->val;
                while(t->next && v == t->next->val) {
                    t=t->next;
                }
               t=t->next; continue;             
            }
            p=p->next;
        }
        p->next=t;
        return dummy.next;
    }
};