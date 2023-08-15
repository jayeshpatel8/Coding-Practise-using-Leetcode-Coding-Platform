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
    ListNode* partition(ListNode* head, int x) {
       ListNode s,b,* small , * big; 
       small = &s, big= &b;

       while (head ){
            if (head->val <  x) 
               small->next=head,small=small->next;
            else
                big->next=head,big=big->next;
           
           head=head->next;
       }
       small->next=b.next;
       big->next=nullptr;
       return s.next;
    }
};