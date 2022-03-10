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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ll1 = len(l1), ll2 = len(l2);
        if (ll1 < ll2) 
            swap(l1,l2),swap(ll1,ll2);
        ListNode * ans=l1,*p;

        int c = 0;
        while(ll1-- > 0){
            int sum = l1->val + (l2 ? l2->val : 0)  + c;
            l1->val = sum %10;
            c = sum > 9;
            p=l1;
            l1 = l1->next, l2 = (l2 ? l2->next : 0) ;
        }

        if (c )
            p->next = new ListNode (1);
        
        return ans;
    }
    int len(ListNode* l){
        int ans=0;
        while(l)
            l=l->next,ans++;
        return ans;
    }
};