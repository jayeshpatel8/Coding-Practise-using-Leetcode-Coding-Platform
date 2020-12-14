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
    ListNode* removeElements(ListNode* head, int val) {
     while(head && head->val == val){
         head=head->next;
     }
     ListNode* pre=head, *cur=head ?head->next:head;   
     while (cur){
         if(cur->val == val ){
             pre->next = cur->next;             
         }
         else 
             pre = cur;
         cur=cur->next;
     }
     return head;
    }
};