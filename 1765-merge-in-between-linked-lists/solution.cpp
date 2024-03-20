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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * h , head, *t;
        head.next =  list1;
        h = &head;
        int c=0;
        while (c != a){
            h=h->next;c++;
        }
        t = h->next;
        h->next = list2;
        
        while (list2 && list2->next) list2 = list2->next;
        
        while(c != b) c++, t=t->next;
        
        list2->next = t->next;
        return head.next;
    }
};
