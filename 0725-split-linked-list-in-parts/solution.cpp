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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (!head) return vector<ListNode*> (k);
        ListNode * h = head , head2;
        int l=0, i=0 ;
        while(h) l++,h=h->next;
        vector<ListNode*> ans;
        h=head;
        
        while (k){
            int j=0,l1 = l/k + (l%k != 0 );            
            auto h1 =&head2;            
            h1->next = nullptr;
            while(j++<l1 && h){
                    h1->next = new ListNode(h->val);
                    h1=h1->next;
                    h=h->next;
            }
            ans.push_back(head2.next);
            i++;
            l -= l1;
            k--;
        }
        return ans;
    }
};
