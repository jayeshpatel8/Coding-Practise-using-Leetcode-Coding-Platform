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
    class comp{
      public:
        bool operator()(ListNode* a, ListNode*b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        ListNode ans ,*t;
        t = &ans;
        for (int i=0; i<lists.size(); i++) if (lists[i]) pq.push(lists[i]);
        while (!pq.empty()){
            t->next = pq.top();pq.pop();
            t=t->next;
            if (t->next) pq.push(t->next);            
        }
        return ans.next;
    }
};