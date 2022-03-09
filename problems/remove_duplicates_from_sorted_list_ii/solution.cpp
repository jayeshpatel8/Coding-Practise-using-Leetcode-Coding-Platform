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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *h=head,dummy,*h1=&dummy;
        dummy.next=h;
        int f[201]={};
        while(h){
            f[100 + h->val]++;
            h=h->next; 
        }
        for(int i=0; i<201;i++){
          if(f[i]==1)
            h1->next->val=i-100,h1=h1->next;
        }
         h1->next=0;
        return dummy.next;
    }
};