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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));
        ListNode *p , *c =head,t;
        t.next = head;
        p= &t;
        while (c){
            while (c && st.count(c->val)){
                c=c->next;
            }
            p->next = c;
            if (c)
                c= c->next;
            p=p->next;
        }
        return t.next;
    }
};
