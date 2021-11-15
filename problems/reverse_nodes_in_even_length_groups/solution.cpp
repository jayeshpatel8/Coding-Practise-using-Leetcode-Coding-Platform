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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* h = head;
        for ( int i = 1; h && h->next; i++){
            int  j = i;
            ListNode* cur = h->next ,*prev = h ;
            if (i>1){
                int len = -1;
                while(h  && (j-- > 0))
                    h = h->next, len++;
                if(i%2 == 0 && h) 
                    prev->next= rev(cur, i), h = cur;
                else if(!h && len %2 == 0 ){                        
                    prev->next= rev(cur, len);
                    h = cur;
                }
            }
        }
        return head;
    }
    ListNode * rev(ListNode * h, int n){
        if (!h->next || n==1)
            return h;
        ListNode * t = rev(h->next, n-1);
        ListNode * next = h->next->next;
        h->next->next = h;
        h->next = next;
        return t;
    }
};