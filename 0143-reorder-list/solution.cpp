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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode * slow = head, *fast = head;
        while(fast && fast->next)
            slow=slow->next, fast = fast->next->next;
        ListNode * prev= NULL, * cur =slow,*next;
        while(cur){ // reverse the list
            next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        // merge list
        ListNode * l1 = head, *l2=prev;
        while(l2->next){
            next = l1->next;
            l1->next = l2;
            l1 = next;
            next = l2->next;
            l2->next = l1;
            l2= next;
        }
    }
};
