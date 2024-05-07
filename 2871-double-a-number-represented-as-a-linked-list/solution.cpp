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
    ListNode* doubleIt(ListNode* head) {
        vector<int> num;
        auto *t = head;
        
        while(t){
            num.push_back(t->val);
            t=t->next;
        }
        int c = 0;
        for (int i=num.size()-1; i>=0; i--){
            int n = num[i] *2 + c;
            num[i] = n%10;
            c = n/10;
        }
        t=head;
        if (c){
            head = new ListNode(c,t);
        }
        
        for (auto i : num){
            t->val = i;
            t=t->next;
        }
        return head;
    }
};
