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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k==0) return NULL ;
        struct Compare{
            bool operator()(ListNode*a, ListNode*b){return  a->val > b->val;}
        };
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        //lists = [[1,4,5],[1,3,4],[2,6]]
        for (int i=0; i<k; i++){
            if (lists[i]){
                pq.push(lists[i]);
            }
        }
        ListNode *res,dummy;
        res = &dummy;
        while (!pq.empty()){
            ListNode *t=pq.top();pq.pop();
            res->next = t;
            if(t->next)
                pq.push(t->next);
            res=res->next;            
        }
        res->next=0;
        return dummy.next;
    }
};