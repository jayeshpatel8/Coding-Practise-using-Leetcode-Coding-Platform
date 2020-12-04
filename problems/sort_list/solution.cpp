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
    ListNode* sortList(ListNode* head) {

        
        if (!head || !head->next) return head;

        return mergesort(head);
    }
    ListNode * mergesort(ListNode * head){
        if (!head || !head->next) return head;
        
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            fast=fast->next;
            if (fast->next){
                fast=fast->next;
                slow=slow->next;
            }
            else
                break;
        }
        //1,2,3,4
        ListNode * a =  slow->next;
        slow->next=NULL;
        
        ListNode *b = head;
        
        return merge( mergesort(a), mergesort(b));
    }
    ListNode * merge(ListNode * a, ListNode* b){
        ListNode * p,dummy;
        p=&dummy;
        p->next=NULL;
        while (a && b){            
            if (a->val < b->val){
                p->next = a;
                a = a->next;                
            }
            else{
                p->next = b;
                b = b->next;
            }
            p=p->next;
        }
        if (!a) p->next = b;
        if (!b) p->next = a;
        return dummy.next;
    }
};