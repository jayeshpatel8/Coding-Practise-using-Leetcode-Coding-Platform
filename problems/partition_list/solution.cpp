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
        ListNode s,l,*s1,*l1;
        s1=&s,l1=&l;
        s.next=NULL; l.next==NULL;
        while (head){
            if (head->val < x){
                s1->next = head;
                s1=s1->next;                
            }
            else{
                l1->next=head;
                l1=l1->next;
            }
            head=head->next;
        }
        s1->next = l.next;
        l1->next=NULL;
        return s.next;
    }
};