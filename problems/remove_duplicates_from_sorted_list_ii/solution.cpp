/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      // if (!head || !head->next) return head;
        ListNode dummy;  dummy.next=head;  
        ListNode* c =&dummy,*cur; 
        ListNode* n ;
        

        while( c && c->next){
            int cur = c->next->val;
            n = c->next->next;
            bool f=false;
            while(n && cur == n->val){
                n= n->next;                                
                f=true;
            }
            
            if (f)
                c->next= n;
            else
                c=c->next;                    
        }
                            
        return dummy.next;
    }
};