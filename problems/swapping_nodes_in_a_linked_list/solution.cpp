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
    ListNode* swapNodes(ListNode* head, int k) {
     int len=0;
        ListNode *t =head,*f=head;
        //[1,2,3,4,5]
        while(t){
            len++;t=t->next;
        }
        int first=1,second=len-k+1;
        if (k > second) swap( k , second);
        while(first <k){
            f=f->next; first++;
        }
        t=f;
        while (first<second){
            f=f->next; first++;
        }
        swap(t->val,f->val);
        return head;
    }
};