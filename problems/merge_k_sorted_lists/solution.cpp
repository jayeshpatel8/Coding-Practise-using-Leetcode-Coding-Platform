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
        set<pair<int,ListNode*>> st;
        ListNode t, * ans = &t;
        for (auto &i : lists) if (i)st.insert({i->val,i});
        while( !st.empty()){
            auto i  = *begin(st);
            st.erase(begin(st));

            ans->next = i.second;
            if (i.second->next) st.insert({i.second->next->val,i.second->next});
            ans=ans->next;
        }
        ans->next=nullptr;
        return t.next;
    }
};