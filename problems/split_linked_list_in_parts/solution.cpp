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
    vector<ListNode*> splitListToParts(ListNode* head, int K) {
        ListNode *cur = head;
        int N = 0;
        while (cur) 
            cur = cur->next, N++;
        int sz  = N / K, rem= N % K;
        cur = head;
        vector<ListNode*> ans(K);
        for( int i=0; i<K; i++){
            ListNode * h = cur;
            for (int j=0; j< sz + (i < rem ? 1 : 0) -1; j++)
                  cur = cur->next;
            ans[i]=h;
            if (cur) {
                ListNode * t = cur; 
                cur = cur->next, 
                t->next=NULL; 
            }
        }
        return ans;
    }
};