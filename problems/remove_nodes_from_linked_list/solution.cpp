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
    ListNode* removeNodes(ListNode* head) {
        ListNode dummy(INT_MAX);
        vector<ListNode *> st{&dummy};
        
        
        for (;head;head=head->next){
            while(!st.empty() && st.back()->val < head->val){
                st.pop_back();
            }
            st.back()->next=head;
            st.push_back(head);            
        }
        st.back()->next=nullptr;
        return dummy.next;
    }
};